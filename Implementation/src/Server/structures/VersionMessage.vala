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

public class OFF.Structures.VersionMessage : GLib.Object, OFF.Structures.Message {

    public VersionMessage () {
    }
    public string generate_message () {
                // version number + type, e.g.:
                // 2021.2.12 REFERENCE
        string version = Application.VERSION + " REFERENCE";
        uchar[] data = {};
        for (int i = 0; i < version.length; i++) {
            data += (uchar) version.data [i];
        }
        return GLib.Base64.encode (data);
    }
}
