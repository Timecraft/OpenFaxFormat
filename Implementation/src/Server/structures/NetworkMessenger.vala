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

public class OFF.Structures.NetworkMessenger : OFF.Structures.Messenger {
    // An implementation of OFF.Structures.Messenger that uses a Network device as the destination
    private string _network_address;
    private GLib.Socket _network_socket;
    private GLib.InetSocketAddress _inet_socket;
    private GLib.FileInputStream gzip_input;
    private uint8[] in_buffer = {};
    
    public NetworkMessenger (File source_file, bool compress = false, string network_address, string dest_file_path) {
        pdf = new Structures.PDFSource (source_file.get_uri ());
        
        pdf.get_size (out width, out height);
        
        this._width_message = new Structures.SizeMessage (width);                  // Protocol specifies width first
        this._height_message = new Structures.SizeMessage (height);
        this._dest_file_path = dest_file_path;
        
        this._network_address = network_address.substring (network_address.last_index_of ("//") + 2, -1);
        
        message ("Width message: " + _width_message.generate_message ());
        message ("Height message: " + _height_message.generate_message ());
        
        try {
            this._network_socket = new GLib.Socket (GLib.SocketFamily.IPV4, GLib.SocketType.STREAM, GLib.SocketProtocol.TCP);
            if (!(this._network_socket is GLib.Socket)) {
                error ("_network_socket is not a Socket!");
            } 
            this._inet_socket = new GLib.InetSocketAddress.from_string (_network_address, 12345);
            if (!(this._inet_socket is GLib.SocketAddress)) {
                error ("_inet_socket is not a SocketAddress!");
            } 
            this._network_socket.connect (this._inet_socket);
        }
        catch (Error e) {
            error ("Unable to connect to server:\t%s", e.message);
        }
        
        
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
    
    public void send_network_message (GLib.File gzip_file) {
        try {
            gzip_input = gzip_file.read ();
            gzip_input.read (in_buffer);
            string in_string = "";
            for (int i = 0; i < in_buffer.length; i++) {
                in_string += ((char) in_buffer [i]).to_string ();
            }
            message ("Buffer:\n\n%s\n\n", in_string);
            _network_socket.send_to (this._inet_socket, in_buffer);
        }
        catch (Error e) {
            error ("Error reading file:\t%s", e.message);
        }
    }
}
