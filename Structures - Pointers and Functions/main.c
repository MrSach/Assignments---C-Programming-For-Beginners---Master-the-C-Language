#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Background
		Studied as part of learning C structures.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		This program prompts the user to enter a product name, price per unit and the quantity through the terminal.
		The program then processes this and generates a total amount based on the unit price and quantity.
		The program demonstrates:
			declaring and instantiating structures
			passing through struct pointers into functions
			dynamic memory allocation of instance member variables
			a more comprehensive function, fgets, to read input, instead of scanf
			use of dereferencing the pointers to instance member variables (-> operator)
			assignment of the memory address of a non-pointer struct variable to the value of a pointer variable of the same struct type.
		
		Author
			Sacha

		Date
			10.3.2022

*/

//Define struct member variables
struct item
{
	char * item_name;
	size_t quantity;
	double price;
	double amount;
};

//Read user input in this function
void read_item (struct item * const s)
{
	//Item name
	char * temp_str [100];
	printf ("\nEnter item name: \n");
	
	//Read in item name up to 100 characters and through the use of fgets
	fgets (temp_str, 101, stdin);
	
	//Dereference the iterator values to get the ASCII character for each letter in the string
	for (char * iterator = temp_str; * iterator > 0; ++iterator)
	{
		//Because fgets also interprets newlines, check if these exist in the input string
		if (* iterator == '\n')
		{
			//Cancel out newlines and carriage returns with null characters in order to terminate string
			//Avoids having a product name with a new line at the end of it!
			* iterator = '\0';
		}
	}
	
	/*
		Check the length of the string
		Also find the number of bytes to allocate per ASCII character
		Declare the memory allocation for a pointer to a character (this is actually a character string in this case)
		Calculate the total memory to allocate for the new string
		Assign the pointer item_name to an appropriate memory location for the appropriate size given
	*/
	s->item_name = (char *) malloc (sizeof (char) * strlen (temp_str));
	
	//Copy the temporary string buffer into the 
	strcpy (s->item_name, temp_str);

	//Quantity entry
	printf ("Enter item quantity: ");
	scanf ("%li", & s->quantity);

	//Price entry
	printf ("Enter item price: ");
	scanf ("%lf", & s->price);

	//Calculate amount
	s->amount = ((double) s->quantity) * s->price;
}

/*
	Display the item structure values
*/
void print_item (const struct item * const s)
{
	printf ("\nDisplaying item...\n");
	printf ("Name = %s\n", s->item_name);
	printf ("Quantity = %li\n", s->quantity);
	printf ("Price = %.2lf\n", s->price);
	printf ("Amount = %.2lf\n", s->amount);
}

int main()
{
	//Instantiate an item with no data predefined
	struct item item_1 = { };
	
	//Instantiate a pointer to an item using the memory location of the first
	struct item * item_2 = & item_1;
	
	//Prompt user to enter data into the pointer to the item
	read_item (item_2);
	
	//Display results
	print_item (item_2);
	
	//Clear memory allocation for dynamically allocated data
	free (item_2->item_name);
	
    return 0;
}
