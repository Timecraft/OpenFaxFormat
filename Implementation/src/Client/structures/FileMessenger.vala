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

public class OFF.Structures.FileMessenger : OFF.Structures.Messenger {
    // An implementation of OFF.Structures.Messenger that uses a File as the destination
    
    
    
    
    public FileMessenger (File source_file, bool compress = false, GLib.FileOutputStream dest_file, string dest_file_path) {
        pdf = new Structures.PDFSource (source_file.get_uri ());

        pdf.get_size (out width, out height);
        
        _width_message = new Structures.SizeMessage (width);                  // Protocol specifies width first
        _height_message = new Structures.SizeMessage (height);
        _version_message = new Structures.VersionMessage ();
        this._dest_file = dest_file;
        this._dest_file_path = dest_file_path;
        
        message ("Version message:\t\t\t" + _version_message.generate_message ());
        message ("Width message:  \t\t\t" + _width_message.generate_message ());
        message ("Height message: \t\t\t" + _height_message.generate_message ());
        send_message (_version_message);
        send_message (_width_message);
        send_message (_height_message);

    }
    
    public override void send_message (Structures.Message message) {
        string string_message = message.generate_message ();
        try {
            _dest_file.write ((string_message + "\n").data);
        }
        catch (Error e) {
            critical ("Error writing to file:\t%s", e.message);
        }
        
    }
    

}
