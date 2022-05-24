#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Background
		Studied as part of character strings.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Program to tokenise strings and to buffer delimited data into an array.
		
		Author
			Sacha

		Date
			7.3.2022

*/

int main()
{
	//Example string to tokenise
	char str [50] = "This - is - a - test! - \n";

	//Prepare array with preallocated size for tokenisation
	const char delim [4] = "-";

	/*
		Loop through string to tokenise
		Initialise pointer to character as the token
		Check if the token ASCII value is not null
		Iterate by calling Standard C Library function strtok again but with NULL instead of the original string to tokenise
	*/
	for (char * token = strtok (str, delim); token > NULL; token = strtok (NULL, delim))
	{
		//Display data in current iteration from the beginning (or since the last delimiter) up to the end of the string (or the next delimiter)
		printf ("%s\n", token);
	}
	
	return 0;
}
