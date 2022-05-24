#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Background
		Studied as part of loops.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Prime Number Generator.
		A small terminal console application that generates prime numbers between 1 and 100.
		
		Author
			Sacha

		Date
			3.3.2022

*/

//Define constants
#define CEIL_LIMIT 100

int main()
{
	//Display title
    printf ("Prime number generator");
    printf ("\n");
    printf ("\n");

	//Declare and initialise starting prime number list
	unsigned int primes [CEIL_LIMIT] =
	{
		2, 3
	};

	//Declare and initialise current ceiling boundary within prime numbers array
	unsigned int temp_ceiling = 1;

	//Outer loop
	//Start at 5, loop through odds until the constant celiling limit
	for (unsigned int i = 5; i < CEIL_LIMIT; i+= 2)
	{
		//Verbose value of i;
		printf ("i = %i\n", i);

		//Calculate the square root of i
		//type cast it into a double, then back to an integer again in order to get just the integer value
		unsigned int root_i = (int) ( (double) sqrt (i) );

		//Declare and initialise boolean, 0 in this case, as we have not found a factor for i yet
		_Bool factored = 0;

		/*
		Loop starts with j for inner loop
		j is used as an index for the primes array.
		Dereferencing primes [j] gives the prime number for the inner loop
		j is initialised to 1, meaning 3 is the first prime number to check divisibility for i
		Loop condition 1 is where the current prime number dereferenced in the array is no greater than the square root of i
		Loop condition 2 is where j is not above the current ceiling boundary for the primes array (keeps within the first 2 elements and only the elements assigned values from within the loop, and not beyond, which would have been initialised to 0
		Iteration action iterates j so it points to the next element in the primes array
		*/
		for (unsigned int j = 1; (primes [j] <= root_i) && (j <= temp_ceiling); ++j)
		{
			//Declare and initialise temporary prime number within inner loop
			unsigned int temp_prime = primes [j];

			//Verbose information for debugging
			printf ("j = %i\n", j);
			printf ("sqrt %i = %i\n", i, root_i);
			printf ("temp_ceiling = %i\n", temp_ceiling);
			printf ("temp_prime = %i\n", temp_prime);

			//Checks if a factor is found
			//If so then exit inner loop for current iteration of outer loop
			if ((i % temp_prime) == 0)
			{
				//Debugging - checks the first factor found for i
				printf ("%i %% %i\n", i, temp_prime);
				printf ("%i is not prime\n", i);

				//Flags true for boolean, thus i has a factor
				factored = 1;

				//Exit inner loop as factor found
				break;
			}
		}

		//For outer loop, if no factors found during inner loop, then assume prime number
		if (factored == 0)
		{
			//Iterate current index to assign next element to primes
			++temp_ceiling;
			printf ("%i is prime\n", i);
			primes [temp_ceiling] = i;
		}

	//Add line break for readability - verbose output
	printf ("\n");
	}

	//Line breaks before final list of prime numbers
	printf ("\n");
	printf ("\n");

	//List prime numbers
	printf ("Prime numbers are:");
	printf ("\n");
	for (unsigned int i = 0; i <= temp_ceiling; ++i)
	{
		printf ("%i\n", primes[i]);
	}

    return 0;
}
