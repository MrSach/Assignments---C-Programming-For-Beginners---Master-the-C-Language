#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Background
		Studied as part of learning character strings.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		This program prompts the user to enter a specific number of text strings into the terminal.
		It then requests the text strings for each element of the array to be input.
		Once the user has entered this data, the program then performs a bubble sort on the text string array.
		The program finally outputs the sorted text strings.
		Skills demonstrated:
			Passing array size as a separate variable as function parameters
			Using variables as part of arrays passed into function parameters
			Dynamic loop control
			Use of common string functions
		
		Author
			Sacha

		Date
			7.3.2022

*/

void display_string (const int str_no, const char strs [str_no] [200])
{
	//Show header for displaying list of strings
	printf ("\nList of strings:\n");
	
	//Loop through the list determined by the number of strings to display
	for (int i = 0; i < str_no; ++i)
	{
		//Display array element as character string
		printf ("%s\n", strs [i]);
	}
}

//Bubble sort function
/*
	Takes the number of strings
	Also takes the array of user-entered strings
	The buffer to store the sorted array then goes into result, which is also passed through as another parameter
*/
void b_sort (const int str_no, const char strs [str_no] [200], char result [str_no] [200])
{
	//Copy strings from source to target
	for (int i = 0; i < str_no; ++i )
	{
		strcpy (result [i], strs [i]);
		
		//Show the strings that have been copied into result
		printf ("\ntest = %s\n", result [i]);
	}

	//Assign variable to increment upon each sort per passthrough
	int pass_sort = 0;
	
	//Sort through result
	for (int i = 0; i < str_no - 1; ++i)
	{
		//If the element in the current position of the bubble sort is alphabetically after the next element, buffer into temporary variable and swap with the next element.
		if (strcmp (result [i], result [i + 1]) > 0)
		{
			char temp [200];
			strcpy (temp, result [i]);
			strcpy (result [i], result [i + 1]);
			strcpy (result [i + 1], temp);
			
			//Increment the number of sorts for current passthrough
			++pass_sort;
		}
		
		/*
			Check if the passthrough has reached the end of the list and if any sorts have been performed during the current passtrough
			If so, reset the iterator and restart the bubble sort loop.
			If not, do not reset the iterator.
			If the iterator has not reached the end of the array, increment by 1.
			If the iterator has reached the end of the array and non bubble sorts have been made, the algortihm is complete and the loop can finally exit. 
		*/
		if ((i == (str_no - 2)) && (pass_sort > 0))
		{
			pass_sort = 0;
			i = -1;
		}
	}
}

int main()
{
	//Prompt the user for the number of text strings to be entered
	printf("Enter the number of strings: ");
	
	//Store the number of strings into an integer variable
	int str_count;
	
	//Read in the number input by the user
	scanf ("%i", & str_count);
	
	//Next, declare the character string array with the number of elements assigned as per the user input
	char str [str_count] [200];
	
	//Prompt the user to enter text for each array element
	for (int i = 0; i < str_count; ++i)
	{
		printf ("\nInput string %i: ", i + 1);
		scanf ("%s", str [i]);
	}
	
	//Display the array before the bubble sort
	display_string(str_count, str);
	
	//Create buffer for the data to be sorted
	char b_sort_str [str_count] [200];
	
	//Call the bubble sort algorithm, passing the number of elements in the character string array, the original string array and the variable to store the sorted array.
	b_sort (str_count, str, b_sort_str);
	
	//Display the bubble sorted array 
	display_string(str_count, b_sort_str);

    return 0;
}
