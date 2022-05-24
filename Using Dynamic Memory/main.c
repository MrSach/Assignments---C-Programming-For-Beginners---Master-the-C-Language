#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Background
		Studied as part of learning pointers.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Program that reads in a user-defined size and user-entered text, then outputs the size and text that were entered by the user, respectively.
		The aim is to enable a different size of memory to be allocated upon execution in response to the user input.
		This demonstrates:
			Dynamic memory allocation
		
		Author
			Sacha

		Date
			9.3.2022

*/

int main ()
{
	//Declare text buffer, but do not initialise yet
	int text_size;
	
	//Declare empty string
	char * str = NULL;

	//Prompt size of text for the user to enter
	printf ("Enter the size of the text: ");
	scanf ("%d", & text_size);

	//Declare and initialise initial string based on entered size
	str = (char *) malloc ((text_size + 1) * sizeof (char));
	if (str == NULL)
	{
		return -2;
	}

	//Prompt user to enter string of characters
	printf ("Enter your text: ");
	scanf (" ");
	fgets (str, ((sizeof (* str)) * (text_size + 1)), stdin);

	//Output data that was entered by the user
	printf ("\nYou entered: \n%s\n", str);
	printf ("\nInitial string buffer size = %d\n", sizeof (* str));

	//Release the string from memory
	free (str);
	str = NULL;

    return 0;
}
