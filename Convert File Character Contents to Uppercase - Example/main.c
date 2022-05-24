#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define TEMPNAME "tempfile.txt"
#define FPATH "testfile2.txt"

/*
	Background
		Studied as part of file input and output.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/
		
	Description
		Reads a predefined input text file.
		Internal program then reads all characters and generates a copy with all characters in uppercase.
		The program the outputs a predefined temporary output file with the changes.
		WARNING: The original file is deleted and the temporary output file is renamed in place of the original!
		
	Author
		Sacha
	
	Date
		11.3.2022 
*/

int main()
{
	//Declare and initialise file pointer variable
	FILE * rfile = NULL;
	
	//Open text file as read only
	rfile = fopen (FPATH, "r");
	
	//Check for success on opening file
	if (rfile == NULL)
	{
		//Generate error in case of failure and output message
		printf ("Error opening file to read\n");
		return -2;
	}
	
	//Declare and initialise second file for writing changes to
	FILE * wtemp = NULL;
	
	//Open second text file for write access only
	wtemp = fopen (TEMPNAME, "w");
	if (wtemp == NULL)
	{
		printf ("Error opening temp file to write\n");
		return -2;
	}

	//Declare and initialise read character buffer to the null character, '\0'
	size_t ch = 0;

	//Loop through the file character by character and get the next character after each iteration
	for (; (ch = fgetc (rfile)) != EOF; )
	{
		//Declare and initialise output buffer character to null character
		size_t oc = 0;
		
		/*Inline boolean - tests if read character is lowercase.
			If true, generate uppercase character for output character.
			If false, copy the read character to the output character.
		*/
		(islower (ch)) ? (oc = toupper (ch)) : (oc = ch);
		
		//Display the output character to be written to the output stream (terminal console).
		printf ("%i ", oc);
		
		//Write the output character to the output file.
		fputc (oc, wtemp);
	}


	//Close all files
	fclose (rfile);
	fclose (wtemp);

	//Reassign all file pointers to null
	rfile = NULL;
	wtemp = NULL;

	//Delete the original file
	remove (FPATH);
	
	//Rename the output file to the same name as the original, thus replacing it
	rename (TEMPNAME, FPATH);

    return 0;
}
