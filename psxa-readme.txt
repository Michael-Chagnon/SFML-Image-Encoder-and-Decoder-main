/**********************************************************************
 *  psxa-readme 
 *  Redid PhotoMagic PS1b                       
 **********************************************************************/

Your name: Michael Chagnon

Hours to complete assignment: 3hrs


/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I redid PS1b PhotoMagic. For changes I switched the 'int' data type on lines 18 and 19
in PhotoMagic.cpp to 'unsigned int' as specified by grader.

I had to encode and decode a picture using a LFSR. I used SFML to process
and display the images. As well as used it to change RGB values for each individuial pixel.

Attached to this repository there are two pictures showing an image of a cat being encoded and
another image of it being decoded.


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
For this project I used a class to create my FibLFSR. Storing seed and tap values in the Private section
and using Public functions to simulate steps given on a number.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
My Transform function takes in a seed and an image to encode or decode. It then calculates RGB values for
each pixel in the image based on the seed and sets the new values.


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
How to encode and decode an image using a FibLFSR

 /**********************************************************************
 *  How to run.
 **********************************************************************/
 make
./PhotoMagic input.png output.png (15 digit code)