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
public class OFF.Widgets.FileChooser : Gtk.Button {
    // This is a minor modification of Granite.Widgets.WelcomeButton
    Gtk.Image? _icon;
    Gtk.FileChooserDialog _file_chooser_dialog;
    Gtk.Label button_title = new Gtk.Label (null);
    Gtk.Grid button_grid = new Gtk.Grid ();
    
    public MainWindow main_window {get; set;}

    public signal void file_selected (File file);
    
    public string title {
        get { return button_title.get_text (); }
        set { 
            button_title.set_text (value);
            
             
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
    public GLib.File? file { 
        owned get {
            return _file_chooser_dialog.get_file ();
        } 
    }

    public FileChooser (MainWindow main_window, string title) {
        Object (
            icon: new Gtk.Image.from_icon_name ("postscript-viewer", Gtk.IconSize.DIALOG),
            title: title
        );
        this.main_window = main_window;
    }
    
    construct {
       
                                                            
         // _file_chooser_dialog = new Gtk.FileChooserDialog    ("Select File", this.main_window, Gtk.FileChooserAction.SAVE,
         //                                                    "Cancel", Gtk.ResponseType.CANCEL,                          // User cancelled opening a file
         //                                                    "Open", Gtk.ResponseType.ACCEPT);                           // User opened a file
                                                            
        

        button_title.get_style_context ().add_class (Granite.STYLE_CLASS_H3_LABEL);
        button_title.halign = Gtk.Align.CENTER;
        button_title.valign = Gtk.Align.CENTER;
        
        
        get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
        
        button_grid.column_spacing = 12;
        button_grid.halign = Gtk.Align.CENTER;
        button_grid.valign = Gtk.Align.CENTER;
        
        button_grid.attach (button_title, 0,1,1,1);
        
        this.add (button_grid);
        
        clicked.connect ( () => {
            message ("Boop");
            
            if (_file_chooser_dialog == null) {
                _file_chooser_dialog = new Gtk.FileChooserDialog    ("Select File", this.main_window, Gtk.FileChooserAction.SAVE,
                                                            "Cancel", Gtk.ResponseType.CANCEL,                          // User cancelled opening a file
                                                            "Open", Gtk.ResponseType.ACCEPT);                           // User opened a file
            
            
                // This is here so that we can call this multiple times.
                // If it were not in the `clicked.connect` block, it would segfault
                _file_chooser_dialog.response.connect ( (/* int */ response_id) => {
                    switch (response_id) {
                        case Gtk.ResponseType.ACCEPT:                       // Set the title of the button to the filename then destroy the dialog
                            title = _file_chooser_dialog.get_filename ().substring (_file_chooser_dialog.get_filename ().last_index_of ("/") + 1, -1);
                            file_selected (this.file);

                        case Gtk.ResponseType.CANCEL:                       // Destroy the dialog
                            _file_chooser_dialog.hide ();
                            _file_chooser_dialog = null;
                            //this.unref ();
                            break;
                    }
                });
            }
            message ("Beep");
            _file_chooser_dialog.show_all ();
            
        });
        
        
    }
}
