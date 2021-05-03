# Open Fax Format/Specification
## v2021.03.03 | 2021-03-03
## License: LGPLv3
## Author: Nicholas Farris

# Definitions
##### Client - Sender.
##### Server - Receiver.
##### Document - Entire PDF Document OR Entire image. Depends on imported type.
##### Page - One section of a PDF OR Entire image. Depends on imported type.
##### Color - integers representing Red Green and Blue.
##### Size - Height x Width.
##### Message - Data containing Version, Size, or Color and pixels.
##### Version - version of the spec being implemented plus the type of spec. e.g. "2021.03.03 REFERENCE".

# Introduction
##### The Open Fax Format/Specification is an open format licensed under the [LGPLv3 license](http://www.gnu.org/licenses/lgpl-3.0.en.html).
* You [MUST](https://www.faa.gov/about/initiatives/plain_language/articles/mandatory/) publish any modifications made to this format under the GNU Lesser General Public License Version 3 or higher and comply with the license. [See this page on ChooseALicense.com for a brief overview on the license](https://choosealicense.com/licenses/lgpl-3.0/).

##### This specification describes a way to transmit data across a network to another computer, typically a printer or printer-connected computer, that is similar to how fax machines transmit data.
###### This specification also describes how to save data to a file that can then be read by a device later to show a Document.

# Overview
## How does this project work?
### Client/Server specification
#### Client
 1. Import Document.
 2. Base64 encode Version and a new line (not encoded), save to file (`.off.gz` extension).
 3. Base64 encode Page width and a new line (not encoded), save to file.
 4. Base64 encode Page height and a new line (not encoded), save to file.
 5. Read Page pixel per pixel.
 6. For each pixel of the same Color, add 1 to pixel count.
 7. When a different Color is reached, encode this data using Base64, insert a new line (not encoded), and save to file.
   * Byte 1: Red: 0 -> 255
   * Byte 2: Green: 0 -> 255
   * Byte 3: Blue: 0 -> 255
   * Bytes 4 -> inifity: Pixels: 1 -> infinity 
 8. Repeat steps 5-8 until end of Page reached. 
 9. On end of Page, insert Base64 encoded "NEWPAGE", insert a new line.
 10. Repeat steps 3-10 for next page.
 11. On end of Document, compress the file using GZip, writing the data to a file with the `.off` extension.
 12. Send this file to the Server over port `12345`
 13. When the file is finished uploading, terminate the connection.
 
#### Server
 1. Listen on port `12345`.
 2. Wait for file (`.off` extension) to be received.
 3. On file received, import file.
 4. Decompress file using GZip.
 5. Base64 decode first Message. This is the Version. Implement logic based on this. 
   * This document will be focused on the current version.
 6. Base64 decode next Message. This is the width.
 7. Base64 decode next Message. This is the height.
 8. Based on the given width and height, create a pixel buffer.
 9. Create integer variable for X position on coordinate plane {`x_coord`}.
 10. Create integer varibale for Y position on coordinate plane {`y_coord`}.
 11. Base64 decode next Message, Base64 decode the data.
   * Convert Byte 1 from uchar to int.
   * Use Byte 1 for color Red.
   * Convert Byte 2 from uchar to int.
   * Use Byte 2 for color Green.
   * Convert Byte 3 from uchar to int.
   * Use Byte 3 for color Blue.
   * Convert Bytes 4 -> infinity from uchar to char.
   * Append converted chars to a string.
   * Convert string to int. 
   * Use int as the amount of pixels to paint.
 12. For each pixel, paint the specified Color, adding one to `x_coord`.
 13. When `x_coord` reaches the width, wrap back to the beginning of the Page, 1 pixel down from the previous line (add one to `y_coord`).
 14. Repeat steps 11 -> 14 until end of Page is reached (row count being one more than height and pixel count being 0).
 15. Print Page (if printer).
 16. Go to step 6 for next Page.
 18. When the end of Document reached, terminate connection.
 
##### For a graphical representation, see [this page](./Client\ Server.html)

### Save To File specification
#### Saving
 * Perform Client procedure, ignoring all references to networking.
 
#### Reading
 * Perform Server procedure, ignoring all references to networking.
