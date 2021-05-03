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

public class OFF.Structures.PDFSource : GLib.Object {
    // This is where the logic to figure out the pixel colors are.
    
    // A lot of help was found at:
    // https://github.com/RonnyDo/ColorPicker/blob/master/src/Widgets/Picker.vala
    // https://github.com/GNOME/evince/blob/c3ac0d3dc7bf05ebb219afcdf3d58f93d01e42cc/libdocument/ev-document-misc.c
    // https://github.com/GNOME/evince/blob/db68e851f3baaba1c80ca127d075b78779f59ee8/backend/pdf/ev-poppler.cc
    private Gdk.Pixbuf source_pixbuf;
    private Gdk.Pixbuf tmp_pixbuf;
    
    private Poppler.Document document;
    private Poppler.Page page;
    
    private Cairo.Context pdf_context;
    private Cairo.ImageSurface pdf_surface;
    
    private double pdf_width;
    private double pdf_height;
    
    public PDFSource (string filename) {
        try {
            document = new Poppler.Document.from_file (filename, "");
        }
        catch (Error e) {
            error ("Unable to open PDF Document: %s", e.message);
        }
        page = document.get_page (0);
        source_pixbuf = create_pixbuf_from_pdf (page);
        //get_red_value (1,0);
    }
    
    private Gdk.Pixbuf create_pixbuf_from_pdf (Poppler.Page pdf_page) {
        double width, height;
        pdf_page.get_size (out width, out height);
        width = GLib.Math.round (width);
        height = GLib.Math.round (height);
        this.pdf_width = width;
        this.pdf_height = height;
        pdf_surface = new Cairo.ImageSurface (Cairo.Format.ARGB32, (int) width, (int) height);
        pdf_context = new Cairo.Context (pdf_surface);
        pdf_page.render (pdf_context);
        
        message ("Width: %s, Height: %s", pdf_surface.get_width ().to_string (), pdf_surface.get_height ().to_string ());
        //pdf_context.set_operator (Cairo.Operator.DEST_OVER);
        //pdf_context.set_source_rgb (1.0,1.0,1.0);
        //pdf_context.paint ();
        
        return Gdk.pixbuf_get_from_surface (pdf_surface, 0, 0, pdf_surface.get_width (), pdf_surface.get_height ());
    }
    
    public void get_size (out double width, out double height) {
        width = this.pdf_width;
        height = this.pdf_height;
    }
    
    public void get_colors (int x, int y, out uint8 red, out uint8 green, out uint8 blue) {
        
        if (pdf_surface == null) {
            critical ("pdf_surface is null");
        }
        tmp_pixbuf = Gdk.pixbuf_get_from_surface (pdf_surface, x, y, 1, 1);
        if (tmp_pixbuf != null) {
            
            
            red = tmp_pixbuf.get_pixels ()[0];
            green = tmp_pixbuf.get_pixels ()[1];
            blue = tmp_pixbuf.get_pixels ()[2];

            
            //`message ("Red value of x:%s y:%s\t\tred:%s\tgreen:%s\tblue:%s\t", x.to_string (), y.to_string (), red.to_string (), green.to_string (), blue.to_string ());
        }
        else {
            red = 255;
            green = 255;
            blue = 255;
            critical ("tmp_pixbuf is null");
        }
    }
}
