#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

	Background
		Studied as part of learning C functions.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		This program is a recreation of the classic game Tic Tac Toe, which is a 2-player game that takes place on a 3 x 3 grid of tiles.
		The goal is to align 3 of the same shape in a row, such as horizontally, vertically or diagonally.
		Here is my attempt to create a console application for this game in C.

	Author
		Sacha
	
	Date
		6.3.2022

*/

#define BOARD_SIZE_X 3
#define BOARD_SIZE_Y 3
#define NUMBER_OF_PLAYERS 2
#define CONSECUTIVE_UNIT_LIMIT 3
#define PLAYER_1_SYMBOL 'X'
#define PLAYER_2_SYMBOL 'O'
#define NUMBER_OF_TURNS (BOARD_SIZE_X * BOARD_SIZE_Y)

typedef unsigned short int word;

void draw_space (word space);
void draw_board (word size_x, word size_y, word board [size_x] [size_y]);
word check_for_win (word size_x, word size_y, word board [size_x] [size_y]);
bool assign_space (word size_x, word size_y, word board [size_x] [size_y], word input, word player_id);
word change_player (word current_player);

void draw_board (word size_x, word size_y, word board [size_x] [size_y])
{
	word counter = 1;
	for (word i = 0; i < size_y; ++i)
	{
		if (i > 0)
		{
			printf ("-----------------");
			printf ("\n");
		}
		printf ("     |     |     ");
		printf ("\n");
		for (word j = 0; j < size_x; ++j)
		{
			if (j > 0)
			{
				printf ("|");
			}
			printf ("  ");
			if (board [j] [i] == 1)
			{
				printf ("%c", PLAYER_1_SYMBOL);
			}
			else if (board [j] [i] == 2)
			{
				printf ("%c", PLAYER_2_SYMBOL);
			}
			else
			{
				printf ("%hi", counter);
			}

			printf ("  ");

			++counter;
		}
		printf ("\n");
		printf ("     |     |     ");
		printf ("\n");
	}
}

/*
returns 1 for player 1
returns 2 for player 2

*/
word check_for_win (word size_x, word size_y, word board [size_x] [size_y])
{
	//Player ID flag
	word pattern = 0;

	//Horizontal pattern loop
	for (word i = 0; (i < size_y) && (pattern == 0); ++i)
	{
		for (word j = 0; (j < size_x - 2) && (pattern == 0); ++j)
		{
			if ((board [i] [j] == board [i] [j + 1]) && (board [i] [j + 1] == board [i] [j + 2]))
			{
				if (board [i] [j] == 1)
				{
					pattern = 1;
				}
				else if (board [i] [j] == 2)
				{
					pattern = 2;
				}
			}
		}
	}

	//Vertical pattern loop
	for (word i = 0; (i < size_y - 2) && (pattern == 0); ++i)
	{
		for (word j = 0; (j < size_x) && (pattern == 0); ++j)
		{
			if ((board [i] [j] == board [i + 1] [j]) && (board [i + 1] [j] == board [i + 2] [j]))
			{
				if (board [i] [j] == 1)
				{
					pattern = 1;
				}
				else if (board [i] [j] == 2)
				{
					pattern = 2;
				}
			}
		}
	}

	//Diagonal pattern loop
	for (word i = 0; (i < size_y - 2) && (pattern == 0); ++i)
	{
		for (word j = 0; (j < size_x - 2) && (pattern == 0); ++j)
		{
			if ((board [i] [j] == board [i + 1] [j + 1]) && (board [i + 1] [j + 1] == board [i + 2] [j + 2]))
			{
				if (board [i] [j] == 1)
				{
					pattern = 1;
				}
				else if (board [i] [j] == 2)
				{
					pattern = 2;
				}
			}
		}
	}

	//Reverse diagonal pattern loop
	for (word i = (size_y - 1); (i < size_y) && (pattern == 0); ++i)
	{
		for (word j = 0; (j < size_x - 2) && (pattern == 0); ++j)
		{
			if ((board [i] [j] == board [i - 1] [j + 1]) && (board [i - 1] [j + 1] == board [i - 2] [j + 2]))
			{
				if (board [i] [j] == 1)
				{
					pattern = 1;
				}
				else if (board [i] [j] == 2)
				{
					pattern = 2;
				}
			}
		}
	}

	return pattern;
}

bool assign_space (word size_x, word size_y, word board [size_x] [size_y], word input, word player_id)
{
	word counter = 1;
	bool assignable = 0;
	for (word i = 0; (i < size_y) && (assignable == 0); ++i)
	{
		for (word j = 0; (j < size_x) && (assignable == 0); ++j)
		{
			if (input == counter)
			{
				if ((board [j] [i] == 0))
				{
					board [j] [i] = player_id;
					assignable = 1;
				}
			}
			++counter;
		}
	}
	return assignable;
}

word change_player (word current_player)
{
	return (current_player == 1)? 2 : 1;
}

int main()
{
	bool game_over = 0;

	word board [(word) BOARD_SIZE_X] [(word) BOARD_SIZE_Y] = { 0 };

	word active_player = 1;

	word turn_counter = 0;

	for (word iterator = 0; game_over == 0; ++iterator)
	{
		system ("clear");
		printf ("\n");
		printf ("\t");
		printf ("Tic Tac Toe");
		printf ("\n");
		printf ("\n");
		printf ("Player 1 (%c) - Player 2 (%c)", PLAYER_1_SYMBOL, PLAYER_2_SYMBOL);
		printf ("\n");
		printf ("\n");

		draw_board ((word) BOARD_SIZE_X, (word) BOARD_SIZE_Y, board);

		//Check digit used to determine win status
		word winning = check_for_win((word) BOARD_SIZE_X, (word) BOARD_SIZE_Y, board);
		if (winning > 0)
		{
			printf ("Player ");
			printf ("%hi", winning);
			printf (" wins.");
			printf ("\n");
			game_over = 1;
		}
		else if (turn_counter >= NUMBER_OF_TURNS)
		{
			printf ("Game over.");
			printf ("\n");
			game_over = 1;
		}
		else
		{
			printf ("Player ");
			printf ("%hi", active_player);
			printf (", enter a number: ");
			word selection;
			scanf ("%hi", & selection);
			printf ("\n");
			bool assigned = assign_space((word) BOARD_SIZE_X, (word) BOARD_SIZE_Y, board, selection, active_player);
			if (assigned == 1)
			{
				active_player = change_player (active_player);
				++turn_counter;
			}
			else
			{
				printf ("Invalid selection, please try again...");
				char resume_prompt = '\0';
				scanf ("%c", & resume_prompt);
				printf ("\n");
			}
		}

	}

	printf ("\n");
    return 0;
}
