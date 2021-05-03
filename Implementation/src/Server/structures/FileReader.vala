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

public class OFF.Structures.FileReader : GLib.Object {
    
    private GLib.File file;
    private GLib.FileInputStream file_input;
    private Widgets.DrawingArea drawing_area;
    private string[] drawing_commands;
    
    private string version;
    private string width;
    private string height;
    
    public abstract signal void page_end_reached (); // When row_num == height + 1 and x = 0, send signal
    
    public FileReader (GLib.File file, Widgets.DrawingArea drawing_area) {
        this.file = file;
        try {
            this.file_input = file.read ();
        }
        catch (Error e) {
            error ("Error reading file:\t%s", e.message);
        }
        this.drawing_area = drawing_area;
    }
    
    public void draw_on_area () {
        
        uint8[32] buffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        string buffer_string = "";
        ssize_t bytes_read = 1;
        
        GLib.ZlibDecompressor decompressor = new GLib.ZlibDecompressor (GLib.ZlibCompressorFormat.GZIP);
        GLib.ConverterInputStream compressor_input = new GLib.ConverterInputStream (file_input, decompressor);
        try {
            while (bytes_read > 0) {
                bytes_read = compressor_input.read (buffer);
                for (int i = 0; i < buffer.length; i++) {
                    buffer_string += ((char) buffer [i]).to_string ();
                }
            }
            if (bytes_read == -1) {
                error ("Error reading file!");
            }
        }
        catch (Error e) {
            error ("Error reading file:\t%s", e.message);
        }
        
        
        
        buffer_string = buffer_string.split ("\n4\n")[0];
        drawing_commands = buffer_string.split ("\n");
//        message ("Full commands:\n\n%s", buffer_string);
        
        decrypt_version ();
        decrypt_width ();
        decrypt_height ();
        decrypt_color ();
    }
    
    
    
    
    private void decrypt_version () {
        version = drawing_commands [0];
        uchar[] version_chars = GLib.Base64.decode (version);
        version = "";
        for (int i = 0; i < version_chars.length; i++) {
            version += ((char) version_chars [i]).to_string ();
        }
        message ("Version:\t%s", version);
    }
    
    private void decrypt_width () { // spec calls for width second
        width = drawing_commands [1];
        uchar[] width_chars = GLib.Base64.decode (width);
        width = "";
        for (int i = 0; i < width_chars.length; i++) {
            width += ((char) width_chars [i]).to_string ();
        }
        message ("Width:\t%s", width);
    }
    
    private void decrypt_height () {
        height = drawing_commands [2];
        
        uchar[] height_chars = GLib.Base64.decode (height);
        height = "";
        for (int i = 0; i < height_chars.length; i++) {
            height += ((char) height_chars [i]).to_string ();
        }
        message ("Height:\t%s", height);
        
        //drawing_area.set_size_request (int.parse (width), int.parse (height));
        drawing_area.set_size (int.parse (width), int.parse (height));
        drawing_area.queue_draw ();
        
    }
    
    private void decrypt_color () {
        for (int i = 3; i < drawing_commands.length; i++) {
            uint8 red, green, blue;
            string pixels_string = "";
            int pixels;
            
            uchar[] command_chars = GLib.Base64.decode (drawing_commands [i]);
            
            red = (uint8) command_chars [0];
            green = (uint8) command_chars [1];
            blue = (uint8) command_chars [2];
            
            for (int character = 3; character < command_chars.length; character++) {
                pixels_string += ((char) command_chars [character]).to_string ();
            }
            
            pixels = int.parse (pixels_string);
            
            //message ("Command:\t%d\t%d\t%d\t%d", red,green,blue, pixels);
            
            drawing_area.set_next_draw_parameters (red, green, blue, pixels);
            drawing_area.queue_draw ();
        }
        page_end_reached ();
        drawing_area.draw_image ();
    }
} 
