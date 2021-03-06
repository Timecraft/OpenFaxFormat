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
public class OFF.Structures.SizeMessage : GLib.Object, OFF.Structures.Message {
    // Class that creates and sends the message containing size data
    private double width_height; // Either width or height, depending on the index of the message
    private string width_height_string { owned get {return width_height.to_string ();}}
    
    public bool did_send = false;

    
    public SizeMessage (double width_height) {
        this.width_height = width_height;
        message ("%f", width_height);
    }
    
    public string generate_message () {
        uchar[] data = {};
        for (int i = 0; i < width_height_string.length; i++) {
            data += (uchar) width_height_string.data [i];
        }
        did_send = true;
        return GLib.Base64.encode (data);
    }
    
}
