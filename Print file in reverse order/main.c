#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
	Background
		Studied as part of file input and output.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		This program reads a predefined text file, reads in one ASCII character at a time, and  Program to display text file in reverse in terminal output.
		fseek and ftell commands are used in order to relocate current position in the file and to reverse the order of processing.
		
	Author
		Sacha

	Date
		11.3.2022

*/

#define FILEPATH "testfile3.txt"

int main()
{
	//File data
	FILE * pfile = NULL;

	//Open file
	pfile = fopen (FILEPATH, "r");

	//Check if file is open
	if (pfile == NULL)
	{
		return -2;
	}

	//Seek to end of file, offset to final letter before last new line.
	fseek (pfile, -2, SEEK_END);

	//Loop through from index at end to beginning
	for (size_t index = 3; ftell (pfile) > SEEK_SET; ++index)
	{
		//Get character at current position
		size_t ch = fgetc (pfile);

		//Check if ASCII value
		if (ch >= 0 && ch < 256)
		{
			printf ("%c", ch);
		}
		//Seek to previous position in file
		fseek (pfile, - index, SEEK_END);
	}

	//Seek to beginning of file
	fseek (pfile, 0, SEEK_SET);

	//Print initial character at beginning of file
	printf ("%c",  fgetc (pfile));
	printf ("\n");

	//Close file and clear pointer references
	fclose (pfile);
	pfile = NULL;

    return 0;
}
