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
    Switch file_network_switch = new Switch (); // Toggle between network and local specifications
    SendButton send_button = new SendButton (); // Button to start the protocol
    
    DrawingArea drawing_area = new DrawingArea (1,1);
    
    Gtk.Label whitespace = new Gtk.Label ("\t\t\t"); 


    GLib.File source_file;                          // Source file
    //GLib.FileInputStream source_file_input;         // InputStream for Source file
    
    bool save_to_file;
    
    Gtk.Settings gtk_settings = Gtk.Settings.get_default ();
    
    

    
    
    public MainWindow (Gtk.Application application) {
        Object (application: application,
                resizable: false,
                height_request: 852,
                width_request: 650
                );
    }
    construct {
        
    
        options.set_row_homogeneous (false);
        options.set_column_homogeneous (true);
        
        source_file_chooser = new FileChooser (this, "Select source file");             // Create FileChooser widgets (Source file)
        
        options.attach (ip_entry, 1, 0, 1, 1);
        options.attach (file_network_switch, 2, 0, 1, 1);
        options.attach (send_button, 3, 0, 1, 1);
        
        options.attach (whitespace, 1, 2, 1, 1);
        
        options.attach (drawing_area, 2, 1, 1, 1);
        
        add_connections ();
        
        gtk_settings.gtk_application_prefer_dark_theme = true;

        
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
        
        // Message processing
        
        Structures.FileReader file_reader = new Structures.FileReader (source_file, drawing_area);
        
        
        bool end_of_page_not_reached = true;
        
        file_reader.page_end_reached.connect ( () => {
            end_of_page_not_reached = false;
        });
        
        while (end_of_page_not_reached) {
            file_reader.draw_on_area ();
            //messenger.next_color_message ();
            GLib.Idle.add (this.send_message.callback);
            yield;
        }
        
        
        //messenger.compress_message ();
        send_button.stop_spinner ();
        yield;
        return;
    }
    
    
    
    // Add signal connections
    private void add_connections () {
        // File/Network Switch connection
        file_network_switch.switch_toggled.connect ( (is_toggled_network) => {
            if (is_toggled_network) {
                options.remove (source_file_chooser);
                options.attach (ip_entry, 1, 0, 1, 1);
                save_to_file = false;
                this.show_all ();
            }
            else {
                options.remove (ip_entry);
                options.attach (source_file_chooser, 1, 0, 1, 1);
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
    }
}
