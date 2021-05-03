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

public class OFF.Widgets.SendButton : Gtk.Button {
    // This is a minor modification of Granite.Widgets.WelcomeButton
    Gtk.Image? _icon;
    Gtk.Label button_title = new Gtk.Label (null);
    Gtk.Grid button_grid = new Gtk.Grid ();
    Gtk.Spinner progress_spinner = new Gtk.Spinner ();
    
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
    
    

    public SendButton () {
        Object (
            icon: new Gtk.Image.from_icon_name ("media-playback-start", Gtk.IconSize.DIALOG),
            title: "Start"
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
    
    public void start_spinner () {
        button_grid.remove (_icon);
            button_grid.attach (progress_spinner, 0, 0, 1, 1);
            progress_spinner.start ();
            this.sensitive = false;
            show_all ();
    }
    public void stop_spinner () {
        progress_spinner.stop ();
        button_grid.remove (progress_spinner);
        button_grid.attach (_icon, 0, 0, 1, 1);
        this.sensitive = true;
        show_all ();
    }
}
