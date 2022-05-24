#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
	Background
		Studied as part of learning C strings.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Asks the user to enter a character string of up to 199 characters long.
		The program then reverses the character string.
		Both the original and reversed string are then output.
	
	Author
		Sacha
	
	Date
		7.3.2022
*/

void reverse_string (const char input [], char result [])
{
	//Get input string length and copy to dedicated variable in function
	int input_length = strlen (input);
	
	//Declare and initialise iterator variable outside loop as this is necessary for null termination character
	int i = 0;
	for (; i < input_length; ++i)
	{
		//Assign from i in reverse order
		result [(input_length - 1) - i] = input [i];
	}
	result [i] = '\0';
}

int main()
{
	//Prompt user for string to reverse
	printf ("Enter a string to reverse: ");
	
	//Initialise new character string
	char test1a [200];
	
	//Read word input by user up to the first space/return key input
	scanf ("%s", test1a);
	
	//Initialise second string with the same length as the first  
	char test1b [strlen(test1a)];
	
	//Reverse the string with the custom string reverse function
	reverse_string (test1a, test1b);
	
	//Show the original string and the reversed string
	printf ("\ntest1a = %s\n", test1a);
	printf ("reversed = %s\n", test1b);

	return 0;
}
