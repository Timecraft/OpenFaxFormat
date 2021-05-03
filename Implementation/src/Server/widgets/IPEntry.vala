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

public class OFF.Widgets.IPEntry : Gtk.Bin {
    // This is a minor modification of Granite.Widgets.WelcomeButton
    Gtk.Image? _icon;
    Gtk.Label _port_box;
    Gtk.Label button_title = new Gtk.Label (null);
    Gtk.Grid button_grid = new Gtk.Grid ();
    
    public MainWindow main_window {get; set;}
    
    public string title {
        get { return button_title.get_text (); }
        set { 
            button_title.set_text (value);
            button_grid.attach (button_title, 0,1,1,1); 
        }
    }
    
    public Gtk.Image? icon {
        get { return _icon; }
        set {
            if (_icon != null) {
            _icon.destroy ();
            }   
            _icon = value;
            if (_icon != null) {
                _icon.set_pixel_size (48);
                _icon.halign = Gtk.Align.CENTER;
                _icon.valign = Gtk.Align.CENTER;
                button_grid.attach (_icon, 0, 0, 1, 1);
            }
        }
    }
    
    public Gtk.Label? port_box {
        get { return _port_box; }
        set {
            if (_port_box != null) {
                _port_box.destroy ();
            }
            _port_box = value;
            if (_port_box != null) {
                _port_box.halign = Gtk.Align.CENTER;
                _port_box.valign = Gtk.Align.CENTER;
                _port_box.set_text ("Listen on port: 12345");
                _port_box.can_focus = false;
                button_grid.attach (_port_box, 0, 2, 1, 1);
            }
        }
    }
    
    public string? port_box_text {
        get { return _port_box.label;}
    }

    public IPEntry () {
        Object (
            icon: new Gtk.Image.from_icon_name ("network-workgroup", Gtk.IconSize.DIALOG),
            title: "Enter IP Address",
            port_box: new Gtk.Label ("")
        );
    }
    construct {
        button_title.get_style_context ().add_class (Granite.STYLE_CLASS_H3_LABEL);
        button_title.halign = Gtk.Align.CENTER;
        button_title.valign = Gtk.Align.CENTER;
        
        
        get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
        
        button_grid.column_spacing = 12;
        button_grid.halign = Gtk.Align.CENTER;
        button_grid.valign = Gtk.Align.CENTER;
        
        this.add (button_grid);
        
    }
}
