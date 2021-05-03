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

public class OFF.Structures.ColorMessage : GLib.Object, OFF.Structures.Message {
    // Message that has the RGB value and the amount of pixels that are to be painted
    public int red = 255;
    public int green = 255;
    public int blue = 255;
    public string pixels;
    
    
    public ColorMessage (uint8 red, uint8 green, uint8 blue, int pixels) {
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.pixels = pixels.to_string ();
        
    }
    
    public string generate_message () {
        uchar[] data = {(uchar) red, (uchar) green, (uchar) blue};
        for (int i = 0; i < pixels.length; i++) {
            data += (uchar) pixels.data [i];
        }
        //message ("Red:%d\t\t\tGreen:%d\t\t\tBlue:%d\t\t\tPixels:%s", red, green, blue, pixels);
        //message (GLib.Base64.encode (data));
        return GLib.Base64.encode (data);
    }
    
    
    
    
}
