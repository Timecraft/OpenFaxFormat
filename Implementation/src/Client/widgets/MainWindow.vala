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

public class OFF.Widgets.MainWindow : Gtk.Window {

    Gtk.Grid options = new Gtk.Grid ();         // Base grid for UI
    IPEntry ip_entry = new IPEntry ();          // IP Entry widget
    FileChooser source_file_chooser;            // Source FileChooser widget
    FileChooser dest_file_chooser;              // Destination FileChooser widget
    Switch file_network_switch = new Switch (); // Toggle between network and local specifications
    SendButton send_button = new SendButton (); // Button to start the protocol


    GLib.File source_file;                          // Source file
    //GLib.FileInputStream source_file_input;         // InputStream for Source file
    
    GLib.File dest_file;                            // Destination file
    GLib.FileOutputStream dest_file_output;         // OutputStream for Destination file
    
    bool save_to_file;
    
    Gtk.Settings gtk_settings = Gtk.Settings.get_default ();
    
    public MainWindow (Gtk.Application application) {
        Object (application: application,
                resizable: false,
                height_request: 480,
                width_request: 720
                );
    }
    construct {
        
    
        //options.set_row_homogeneous (true);
        options.set_column_homogeneous (true);
        
        options.set_row_spacing (12);
        options.set_column_spacing (12);
        
        source_file_chooser = new FileChooser (this, "Select source file");             // Create FileChooser widgets (Source file)
        dest_file_chooser = new FileChooser (this, "Select destination file");          // Create FileChooser widgets (Destination file)
        
        options.attach (source_file_chooser, 0, 0, 1, 1);
        options.attach (ip_entry, 1, 0, 1, 1);
        options.attach (file_network_switch, 1, 1, 1, 1);
        options.attach (send_button, 2, 0, 1, 1);
        
        
        gtk_settings.gtk_application_prefer_dark_theme = true;
        
        
        add_connections ();
        
        
        
        this.add (options);
        this.show_all ();

    }
    
    private async void send_message () {
        
        /*
        // Open the input stream
        try {
            source_file_input = source_file.read ();
        }
        catch (Error e) {
            error ("Cannot read file %s: %s", source_file.get_path (), e.message);
        }
        */
        GLib.Idle.add (this.send_message.callback);
        send_button.start_spinner ();
        yield;
        
        Structures.Messenger messenger;
        
         if (save_to_file) { // Open output stream
            try {
                dest_file_output = dest_file.replace (null, false, GLib.FileCreateFlags.NONE);
                
            }
            catch (Error e) {
                error ("Cannot create file %s: %s", dest_file.get_path (), e.message);
            }
            // Create a messenger that is savvy with files
            messenger = new Structures.FileMessenger (source_file, false, dest_file_output, (dest_file.get_path ().substring (0, dest_file.get_path ().last_index_of ("."))));
        }
        else {  // Send to IP
            // Create a messenger that is savvy with IP Addresses
            messenger = new Structures.NetworkMessenger (source_file, false, ip_entry.entry_box_text, (source_file.get_path ().substring (0, source_file.get_path ().last_index_of (".")) + ".off"));
        }
        
       
        
        bool end_of_page_not_reached = true;
        messenger.page_end_reached.connect ( () => {
            end_of_page_not_reached = false; // end of page reached
            
        });
        
        
        
        
        while (end_of_page_not_reached) {
            
            messenger.next_color_message ();
            GLib.Idle.add (this.send_message.callback);
            yield;
        }
        
        
        messenger.compress_message ();
        send_button.stop_spinner ();
        
        options.attach (new Gtk.Image.from_surface (Structures.PDFSource.pdf_surface), 1, 2, 1, 1);
        show_all ();
        
        GLib.Idle.add (this.send_message.callback);
        
        yield;
        
        
        
        
        return;
    }
    
    
    
    // Add signal connections
    private void add_connections () {
        // File/Network Switch connection
        file_network_switch.switch_toggled.connect ( (is_toggled_network) => {
            if (is_toggled_network) {
                options.remove (dest_file_chooser);
                options.attach (ip_entry, 1, 0, 1, 1);
                save_to_file = false;
                this.show_all ();
            }
            else {
                options.remove (ip_entry);
                options.attach (dest_file_chooser, 1, 0, 1, 1);
                save_to_file = true;
                this.show_all ();
            }
        });
        
        // Send Button connection
        send_button.clicked.connect ( () => {
                send_message.begin ();
        });
        
        // Source File Chooser connection
        source_file_chooser.file_selected.connect ( (file) => {
            source_file = file;
        });
        
        // Dest File Chooser connection
        dest_file_chooser.file_selected.connect ( (file) => {
            dest_file = GLib.File.new_for_path (file.get_path () + ".gz");
        });
    }
}
