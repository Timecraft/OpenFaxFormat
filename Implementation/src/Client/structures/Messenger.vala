/*


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

public abstract class OFF.Structures.Messenger : GLib.Object {
    // Container class for all of the messaging data
    protected Structures.SizeMessage    _height_message;
    protected Structures.SizeMessage    _width_message;
    protected Structures.VersionMessage _version_message;
    protected Structures.ColorMessage   _color_message;
    protected Structures.PDFSource      pdf;
    
    private GLib.ConverterOutputStream  compressor_output;
    protected GLib.FileOutputStream     _dest_file;
    protected string                    _dest_file_path;
    
    public abstract signal void page_end_reached (); // When row_num == height + 1 and x = 0, send signal
    
    protected double width;
    protected double height;
    
    protected int x = 0;
    protected int row_num = 0;
    
    
    protected bool compress;
    
    protected uint8 red = 255;
    protected uint8 green = 255; 
    protected uint8 blue = 255;
    protected uint8 last_red = 255;
    protected uint8 last_green = 255;
    protected uint8 last_blue = 255;
    
    public abstract void send_message (Structures.Message message);
    
    

    
    public void compress_message () {
        GLib.File gzip_file;
        try {
            gzip_file = GLib.File.new_for_path (_dest_file_path + ".gz");
            GLib.File off_file = GLib.File.new_for_path (_dest_file_path);
            
            GLib.FileOutputStream _off_file_output = off_file.replace (null, false, GLib.FileCreateFlags.NONE);
            GLib.ZlibCompressor compressor = new GLib.ZlibCompressor (GLib.ZlibCompressorFormat.GZIP);
            compressor_output = new GLib.ConverterOutputStream (_off_file_output, compressor);
        
            GLib.FileInputStream gzip_file_input = gzip_file.read ();
           
            compressor_output.splice (gzip_file_input, GLib.OutputStreamSpliceFlags.CLOSE_TARGET);
        }
        catch (Error e) {
            critical ("Could not flush buffer: %s", e.message);
        }
        
        
        try {
            gzip_file.@delete ();
        }
        catch (Error e) {
            critical ("Cannot delete file: %s", e.message);
        }
    }
    
    public void next_color_message () {
        bool is_same_color = true;
        
        int pixels = 1;
        //double red_double, green_double, blue_double;
        if (!_width_message.did_send) {
            this.send_message (_width_message);
        }
        if (!_height_message.did_send) {
            this.send_message (_height_message);
        }
        
        while (is_same_color) {
            pdf.get_colors (x, row_num, out red, out green, out blue);

            if (compress) {
                red = (uint8) (GLib.Math.round (((red / 255) * 20)) * 255);
                green = (uint8) (GLib.Math.round (((green / 255) * 20)) * 255);
                blue = (uint8) (GLib.Math.round (((blue / 255) * 20)) * 255);
            }   
            
            if (row_num == height){// && x == 0) {
                page_end_reached ();
                is_same_color = false;
            } 
            
            if (last_red != red || last_green != green || last_blue != blue || row_num == height) {
                //message ("last_red: %d, red: %d\tlast_green: %d,green: %d\tlast_blue: %d, blue: %d", last_red, red, last_green, green, last_blue, blue);
                is_same_color = false;
                message ("Color Mesage: %d,%d,%d,%d", last_red, last_green, last_blue, pixels);
                _color_message = new ColorMessage (last_red, last_green, last_blue, pixels);
                this.send_message (_color_message);
                //message ("Color Mesage: %d,%d,%d", red, green, blue);
            }
            last_red = red;
            last_green = green; 
            last_blue = blue;
            pixels++;
            x++;
            if (x == width) {
                x = 0;
                row_num++;
            }
            
            
        }
        
    }
    

} 
