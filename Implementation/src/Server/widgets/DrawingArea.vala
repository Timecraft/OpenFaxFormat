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

public class OFF.Widgets.DrawingArea : Gtk.Image {
    private double x_coord = 0;
    private double y_coord = 0;
    private int width;
    private int height;
    
    private double red = 0;
    private double blue = 0;
    private double green = 0;
    private int pixels = 0;
    
    private bool do_draw = false;
    private bool size_was_set = false;
    private bool has_not_initialized = true;
    
    private Cairo.Context class_context;
    private Cairo.Surface class_surface;
    
    private Structures.DrawCommand[] command_list = {};
    
    public DrawingArea (int width, int height) {
        Object (
            height_request: height,
            width_request : width
        );
        this.height = height;
        this.width = width;
    }
    
    public void set_next_draw_parameters (uint8 red, uint8 green, uint8 blue, int pixels) {
        this.red = red / 255.0;
        this.green = green / 255.0;
        this.blue = blue / 255.0;
        this.pixels = pixels;
        do_draw = true;
        
        //message ("Red:%f, Green:%f, Blue:%f",this.red, this.green, this.blue);
        while (this.pixels >= this.width) {
            this.command_list += new Structures.DrawCommand (this.red, this.green, this.blue, this.width);
            message ("(uints) Red:%d, Green:%d, Blue:%d", red, green, blue);
            this.pixels -= width;
        }
        if (this.pixels > 0) {
            this.command_list += new Structures.DrawCommand (this.red, this.green, this.blue, this.pixels);
            message ("(uints) Red:%d, Green:%d, Blue:%d", red, green, blue);
        }
        
        
        
        //draw (this.class_context);
    }
    
    public void set_size (int width, int height) {
        this.height = height;
        this.width = width;
        
        this.height_request = height;
        this.width_request = width;
        
        class_surface = new Cairo.ImageSurface (Cairo.Format.ARGB32, this.width, this.height);
        class_context = new Cairo.Context (class_surface);
        
        size_was_set = true;
    }
    
    public void draw_image () {
        
        class_context.set_source_rgba (1,1,1,1);
        class_context.paint ();
        
        x_coord = 0;
        y_coord = 0;
        for (int i = 0; i < command_list.length; i++) {
            command_list [i].draw (class_context, ref x_coord, ref y_coord, this.width);
            if (x_coord > width) {
                critical ("x_coord is over the width!");
            }
        }
        x_coord = 0;
        y_coord = 0;
        set_from_surface (this.class_surface);
    }
    
    // public override bool draw (Cairo.Context drawer) {
    // /*
    //     if (has_not_initialized && size_was_set) {
    //         this.class_context = drawer;
    //         has_not_initialized = false;
    //     }
    //     if (do_draw) {
    //         //drawer.push_group ();
    //         //var group = drawer.pop_group ();
    //         drawer.set_line_width (1);
    //         message ("Drawing %d pixels", pixels);
    //         // if the amount of pixels goes over the amount it takes to get to the width....
    //         
    //         
    //         while (x_coord + pixels >= width) {
    //             drawer.set_source_rgba (red, green, blue, 1);
    //             drawer.move_to (x_coord, y_coord);
    //             drawer.line_to (width, y_coord);
    //             
    //             
    //             if (x_coord != 0) {
    //                 pixels -= (int) x_coord;
    //                 x_coord = 0;
    //                 
    //             }
    //             else {
    //                 pixels -= width;
    //                 
    //             }
    //             y_coord ++;
    //             
    //             //drawer.stroke ();
    //         }
    //         
    //             drawer.move_to (x_coord, y_coord);
    //             
    //             drawer.line_to (x_coord + pixels, y_coord);
    //             
    //             x_coord += pixels;
    //             
    //             if (x_coord == width) {
    //                 y_coord ++;
    //                 x_coord = 0;
    //             }
    //         //drawer.stroke ();
    //         //drawer.mask (group);
    //         message ("Drew portion");
    //     }
    //     else {
    //         
    //     }
    //     do_draw = false;
    //     */
    //     drawer.set_source_rgba (1,1,1,1);
    //     drawer.paint ();
    //     x_coord = 0;
    //     y_coord = 0;
    //     for (int i = 0; i < command_list.length; i++) {
    //         command_list [i].draw (drawer, ref x_coord, ref y_coord, width);
    //     }
    //     x_coord = 0;
    //     y_coord = 0;
    //     
    //     //drawer.set_line_width (1);
    //     //if (do_draw) {
    //     /*
    //         for (int i = 0; i < 10; i++) {
    //             drawer.set_source_rgb (1.0, 1.0, 1.0);
    //             drawer.move_to (0,y_coord);
    //             drawer.line_to (width, y_coord);
    //             y_coord++;
    //             drawer.stroke ();
    //             //drawer.save ();
    //         }
    //         for (int i = 0; i < 10; i++) {
    //             drawer.set_source_rgb (0.0, 0.0, 0.0);
    //             drawer.move_to (0,y_coord);
    //             drawer.line_to (width, y_coord);
    //             y_coord++;
    //             drawer.stroke ();
    //         }
    //         */
    //         do_draw = false;
    //         //drawer.paint ();
    //     //}
    //     //message ("Total pixels painted: %d", Structures.DrawCommand.total_pixels);
    //     return false;
    // }
}}
