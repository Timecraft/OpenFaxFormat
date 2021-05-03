void main () {
	// Sample Data
        uint8 red = 255;
        uint8 green = 255;
        uint8 blue = 0;
        int pixels = 484704;
	
	// Convert pixels to string so we can encode it
        string pixels_string = pixels.to_string ();
	
	// Convert RGB to uchars for encoding (uchar is uint8, but we just want to make sure it works)
        uchar[] data = {(uchar) red, (uchar) green, (uchar) blue};

	// Add byte data of the stringified pixels
        for (int i = 0; i < pixels_string.length; i++) {
                data += (uchar) pixels_string.data [i];
        }

	// Base64 encode
        string test = GLib.Base64.encode (data);
	//message would be sent to target here, using `test`



        string test_decode = "";
	//Decode first three bytes of the encoded data (RGB)
        test_decode += GLib.Base64.decode (test)[0].to_string ();
        test_decode += GLib.Base64.decode (test)[1].to_string ();
	test_decode += GLib.Base64.decode (test)[2].to_string ();

	//Decode all other bytes of the encoded data (pixels)
        string temp_string = "";
        GLib.Bytes temp_string_bytes;
        for (int i = 3; i < GLib.Base64.decode (test).length; i++) {
                temp_string += ((char) GLib.Base64.decode (test)[i]).to_string ();
        }
	
        //test_decode += temp_string;
        message (test);
        message (test_decode);
        message (temp_string);
        return;

/*
Right now the problem with this is converting the pixels data back to a number.
Vala's uchar.to_string () function provides the ascii representation of the character
	The reason is because a uchar is a uint8, so we're asking for the representation of the uint8.
	If the uint8 is "255", we are asking for the string "255".
The integers put out are ascii representations of each digit.
We need to convert the ascii representation to the actual form so that we can then parse the string for the int and deal with things from there.
*/

/*
Typecasting the uchar to a char and then calling `.to_string ()` does exactly what I want
*/
}
