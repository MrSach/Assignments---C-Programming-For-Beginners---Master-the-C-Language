#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Background
		Studied as part of controlling program flow.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/
		
	Author
		Sacha
		
	Purpose
		Generates a random number and prompts the user to guess.
		The random number is between 0 and 20 inclusive.
		User is given 5 attempts to guess the number correctly.
		If they guess the number before the threshold then they win, otherwise they lose.
		Have fun!
		
	Date
		3.3.2022
*/

int main()
{
	//Assign fixed constant for maximum number of attempts
	const int max_attempts = 5;

	//Display title
	printf ("This is a guessing game.");
	printf ("\n");
	printf ("I have chosen a number between 0 and 20 which you must guess.");
	printf ("\n");
	printf ("\n");

	//Get current time
	time_t t;

	//Generate seed for random number from current time
	srand ( (unsigned) time & t);

	//Generate random number from seed
	unsigned int random_number = rand () % 21;

	//Declare and initialise conditional variables to control the application flow
	_Bool player_wins = 0;
	unsigned int attempt = 0;

	//Begin loop for the guessing game
	//Loop iterates when the game is active and the attempts are below the threshold
	for (unsigned int i = 0; attempt < max_attempts; ++i)
	{

		//Display attempts remaining
		printf ("You have ");
		printf ("%i", max_attempts - attempt);
		printf (" ");
		if (attempt == (max_attempts - 1))
		{
			printf ("try");
		}
		else
		{
			printf ("tries");
		}
		printf (" left.");
		printf ("\n");

		//Prompt the user to enter random whole number between 0 and 20
		printf ("Enter a guess: ");

		//User enters a number into the terminal
		unsigned int user_input;
		scanf ("%i", & user_input);

		//Check if the number entered is within bounds
		if (user_input >= 0 && user_input <= 20)
		{
			//Check the user entered number matches the random number
			if (random_number == user_input)
			{
				player_wins = 1;
				break;
			}
			else
			{
				//Incorrect guess routine
				//Increment attempts
				++attempt;
				
				//Show guessed number
				printf ("Sorry, ");
				printf ("%i", user_input);
				printf (" is wrong. My number is ");
				
				//Output hint
				if (random_number < user_input)
				{
					printf ("less");
				}
				else if (random_number > user_input)
				{
					printf ("greater");
				}
				printf (" than that.");
				printf ("\n");
				printf ("\n");
			}
		}
		else
		{
			//Reject invalid input with message
			printf ("Please enter a number between 0 and 20.");
			printf ("\n");
		}

	}

	//Check if player has already guessed the correct number
	//Game Over screen
	if (player_wins == 1)
	{
		printf ("Congratulations. You guessed it!");
		printf ("\n");
	}
	else
	{
		printf ("Game Over. You have run out of guesses.");
		printf ("\n");
	}

    return 0;
}
