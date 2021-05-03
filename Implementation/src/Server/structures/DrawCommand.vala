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

public class OFF.Structures.DrawCommand : GLib.Object {
        public static int total_pixels = 0;
        private double red;
        private double green;
        private double blue;
        private int pixels;
    
    public DrawCommand (double red, double green, double blue, int pixels) {
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.pixels = pixels;
        message ("Pixels: %d", this.pixels);
        //message ("Drew: \tRed: %f\tGreen: %f\tBlue: %f\tPixels: %i", this.red, this.green, this.blue, this.pixels);
    }
    
    public void draw (Cairo.Context context, ref double x_coord, ref double y_coord, int width) {
        //message ("Drawing");
        //message ("Drawing: %f,%f,%f,%d", this.red, this.green, this.blue, this.pixels);
        
        if (this.pixels > 0) {
        
            context.set_line_width (1);
            context.move_to (x_coord, y_coord);
            context.set_source_rgb (this.red, this.green, this.blue);
            int temp_pixels = this.pixels;
            total_pixels += this.pixels;
            
            //message ("Coord: %f", x_coord);
            
             while (x_coord + temp_pixels >= width) {
                
                context.move_to (x_coord, y_coord);
                context.line_to (width, y_coord);
                
                
                if (x_coord != 0) {
                    
                    temp_pixels -= (width - (int) x_coord);
                    x_coord = 0;
                    //message ("new line mid page");
                }
                else {
                    temp_pixels -= width;
                    x_coord = 0;
                    //message ("new line");
                }
                y_coord ++;
            }
            context.move_to (x_coord, y_coord);
            
            context.line_to (x_coord + temp_pixels, y_coord);
            
            x_coord += temp_pixels;
            
            if (x_coord >= width) {
                y_coord ++;
                x_coord = 0;
            }
            
            context.stroke ();
       }
       
    }
    
}
