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

public class OFF.Widgets.Switch : Gtk.Grid {
    // Determines whether we save to a file or send to a network device
    Gtk.Switch file_network_switch = new Gtk.Switch ();
    
    public signal void switch_toggled (bool is_toggled_network); // A signal to tell us if the switch has been toggled to the `network` state
    
    public Switch () {
        Object (
            //column_homogeneous: true
            //row_homogeneous: true
        );
        file_network_switch.set_active (true);
        attach (new Gtk.Image.from_icon_name ("postscript-viewer", Gtk.IconSize.DND), 0,0,1,1);
        attach (file_network_switch, 1,0,1,1);
        attach (new Gtk.Image.from_icon_name ("network-workgroup", Gtk.IconSize.DND), 2,0,1,1);
        
        column_spacing = 20;
        halign = Gtk.Align.CENTER;
        valign = Gtk.Align.CENTER;
        
        file_network_switch.state_set.connect ( (is_toggled_network) => { // True if network is selected
            switch_toggled (is_toggled_network);
            return true;
        });
    }
}
