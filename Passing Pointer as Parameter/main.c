#include <stdio.h>
#include <stdlib.h>

/*
	Background
		Studied as part of learning pointers.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Passing arguments by value is how C transfers data between functions.
		C does not support directly passing by reference.
		Every parameter is assigned its own memory address in the stack in order to keep them separate from pre-existing variables from other functions. 
		So, how does a function gain direct access to a pre-existing variable?
		Through declaring parameters as pointers!
		
		In this example program, a variable x is declared in main.
		The memory address of x is then passed as an argument (&x) to the function square_me.
		square_me's parameter y (pointer, *y) will need its own memory location.
		The value of this pointer is copied over from main.
		The value is the memory location of the variable x from main, so now the pointer variable y in square_me can access and change the data stored in main's x variable.
		The pointer value will need to be dereferenced when handling the values of the original variables, but otherwise the variables can be handled much like in the parent functions.
		
		Consider the following example:
		
			Variable	Function	Value
			& x		main		0x200
			x		main		5
			& y		square_me	0x400
			y		square_me	0x200
			* y		square_me	5
			
		Because square_me's variable y is actually a pointer to main's variable x, it will now have access to main's variable x, almost just like main would.
		
			Variable	Function	Value
			& x		main		0x200
			x		main		25
			& y		square_me	0x400
			y		square_me	0x200
			* y		square_me	25
			
		Non-pointer variables are already dereferenced without the need for an asterisk.
		In this case x gets the value stored in variable x in main.
		
		To get the memory address for a non-pointer variables, the ampersand operator (&) is needed.
		In this case the memory address is accessed through &x in main.
		
		Pointer variables have multiple layers of memory addresses.
		To access the base memory location of the pointer itself, the ampersand operator (&) can be used.
		In square_me, &y can be used to get pointer y's own unique memory address.
		
		Without the ampersand or asterisk, the memory location of a different variable may be stored in a pointer.
		To get the value of the pointer, which is a memory location to another variable no operator is needed.
		In square_me, y would be used to get the memory location of main's x variable.
		
		The value of the variable pointed to is accessed from the pointer through using the asterisk (*) operator on the pointer.

	Author
		Sacha
		
	Date
		9.3.2022
*/

void square_me (int * y)
{
	* y *= * y;
}

int main()
{
	//Declare and initialise x in main function to the value of 5 
	int x = 5;
	
	//Display value of x before calling example function
	printf ("\nx = %d\n", x);
	
	//Call example function with the address of x as the argument
	square_me (& x);
	
	printf ("\nx = %d\n", x);
	return 0;
}
