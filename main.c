#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

	Background
		Studied as part of learning C character strings.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Recreates common C string functions as a learning exercise.
		This performs 3 major functions:
			determines the length of a character string
			concatenates two strings together
			compares two strings by ASCII character

	Author
		Sacha
	
	Date
		7.3.2022

*/

int string_count (const char str []);
void string_concatenate (const char str1 [], const char str2 [], char result []);
bool string_compare (const char str1 [], const char str2 []);

/*
	Length of string
	This function reads a character string with no predefined size.
	The temporary buffer for the length is assigned a value of 0 by default and increases for each non-null ('\0') character parsed through the loop.
	Upon each iteration the counter increases by 1, which will eventually decide the length of the character string.
	This function returns the length of the string that is passed as a parameter into the function.
*/
int string_count (const char str [])
{
	int counter = 0;
	for (; str [counter] != '\0'; ++counter)
	{

	}
	return counter;
}

/*
	Function to concatenate two strings together.
	This function takes two strings of no predetermined size, and a third variable to store the result into.
	This uses the string_count from the previous function in order to determine the string size for both the strings to concatenate.
	This is to decide the limits when copying each string into result.
	As this directly writes to result, there is no need to return a variable here.	
*/
void string_concatenate (const char str1 [], const char str2 [], char result [])
{
	//Get length of both strings to combine into 3rd string
	const int str1_l = string_count (str1);
	const int str2_l = string_count (str2);

	//Copy string 1 into string 3
	for (int i = 0; i <= str1_l; ++i)
	{
		result [i] = str1 [i];
	}

	//Copy string 2 into string 3
	for (int i = 0; i <= str2_l; ++i)
	{
		result [i + str1_l] = str2 [i];
	}
}

/*
	String compare function.
	Compares two strings and checks if they both match.
	Strings are compared by character.
	If there is a mismatch the default value of false will be returned.
	If the end of both strings is reached simultaneously and no mismatches have been found then the value of true is returned.
	Returns boolean.
*/
bool string_compare (const char str1 [], const char str2 [])
{
	bool equality = 0;
	int str1_l = string_count(str1);
	int str2_l = string_count(str2);
	if (str1_l == str2_l)
	{
		for (int i = 0; i <= str1_l; ++i)
		{
			if (str1 [i] != str2 [i])
			{
				break;
			}
			else if (i == str1_l)
			{
				equality = 1;
			}
		}
	}
	return equality;
}

int main()
{
	//Test custom length of string function
	char test_1 [10] = "ABCDEFGHI";
	char test_1b [25] = "Hello, my name is ...???";
	char test_1c [5] = "TEST";
	printf ("Length of %s = %i", test_1, string_count (test_1));
	printf ("\n");
	printf ("Length of %s = %i", test_1b, string_count (test_1b));
	printf ("\n");
	printf ("Length of %s = %i", test_1c, string_count (test_1c));
	printf ("\n");
	printf ("\n");

	//Test custom concatenate string function
	char test2a [10] = "Hello, ";
	char test2b [15] = "World!";
	char test2c [string_count(test2a) + string_count(test2b) + 1];
	string_concatenate (test2a, test2b, test2c);
	printf ("Test2a = %s", test2a);
	printf ("\n");
	printf ("Test2b = %s", test2b);
	printf ("\n");
	printf ("Test2c = %s", test2c);
	printf ("\n");
	printf ("\n");

	char test2d1 [100] = "ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE TEN";
	char test2d2 [100] = " ELEVEN TWELVE THIRTEEN FOURTEEN FIFTEEN";
	char test2d3 [string_count(test2d1) + string_count(test2d2) + 1];
	string_concatenate (test2d1, test2d2, test2d3);
	printf ("Test2d1 = %s", test2d1);
	printf ("\n");
	printf ("Test2d2 = %s", test2d2);
	printf ("\n");
	printf ("Test2d3 = %s", test2d3);
	printf ("\n");
	printf ("\n");

	//Test equality between strings
	char test3a [10] = "ABCDEFGH";
	char test3b [10] = "ABCDEFGH";
	bool test3_bool = string_compare (test3a, test3b);
	printf ("Test3a = %s", test3a);
	printf ("\n");
	printf ("Test3b = %s", test3b);
	printf ("\n");
	printf ("Test3_bool = %i", test3_bool);
	printf ("\n");
	printf ("\n");
	char test3c [10] = "IJKLMN";
	char test3d [10] = "IJOPQR";
	bool test3_bool2 = string_compare (test3c, test3d);
	printf ("Test3c = %s", test3c);
	printf ("\n");
	printf ("Test3d = %s", test3d);
	printf ("\n");
	printf ("Test3_bool2 = %i", test3_bool2);
	printf ("\n");
	printf ("\n");
	char test3e [10] = "TEST";
	char test3f [10] = "TEST 60";
	bool test3_bool3 = string_compare (test3e, test3f);
	printf ("Test3e = %s", test3e);
	printf ("\n");
	printf ("Test3f = %s", test3f);
	printf ("\n");
	printf ("Test3_bool3 = %i", test3_bool3);
	printf ("\n");
	printf ("\n");
	char test3g [10] = "TEST7";
	char test3h [10] = "TEST8";
	bool test3_bool4 = string_compare (test3g, test3h);
	printf ("Test3g = %s", test3g);
	printf ("\n");
	printf ("Test3h = %s", test3h);
	printf ("\n");
	printf ("Test3_bool4 = %i", test3_bool4);
	printf ("\n");
	printf ("\n");

    return 0;
}
