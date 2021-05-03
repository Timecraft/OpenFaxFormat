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

private const ZlibCompressorFormat FORMAT = ZlibCompressorFormat.GZIP;

private void convert (File source, File dest, Converter converter) throws Error {
	var src_stream = source.read ();
	var dst_stream = dest.replace (null, false, 0);
	var conv_stream = new ConverterOutputStream (dst_stream, converter);

	// 'splice' pumps all data from an InputStream to an OutputStream
	conv_stream.splice (src_stream, 0);
}

public int main (string[] args) {
	if (args.length < 2) {
		print ("Usage: %s FILE\n", args[0]);
		return 0;
	}

	var infile = File.new_for_commandline_arg (args[1]);
	if (!infile.query_exists ()) {
		stderr.printf ("File '%s' does not exist.\n", args[1]);
		return 1;
	}

	//var zipfile = File.new_for_commandline_arg (args[1] + ".gz");
	var outfile = File.new_for_commandline_arg (args[1] + "_out");

	try {
		//convert (infile, zipfile, new ZlibCompressor (FORMAT));
		convert (infile, outfile, new ZlibDecompressor (FORMAT));
	} catch (Error e) {
		stderr.printf ("%s\n", e.message);
		return 1;
	}

	return 0;
}
