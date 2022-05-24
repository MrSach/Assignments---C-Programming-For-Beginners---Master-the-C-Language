#include <stdio.h>
#include <stdlib.h>

/*
	Background
		Studied as part of arrays.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		Terminal program to show examples of data stored in C arrays.
		This example demonstrates displaying the contents of multidimensional arrays, which are double floating point numbers.
		The numbers represent an artifical monthly rainfall over a 5-year average, starting from 2010.
		Totals and averages are then calculated, which are also output to the terminal.
		
		Author
			Sacha

		Date
			4.3.2022

*/

//Constants
#define MONTHS 12
#define YEARS 5
#define INIT_YEAR 2010

//Main function
int main()
{

	//Month names
	const char * month_name [12] =
	{
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec"
	};

	//Rainfall by year and month
	double rainfall [YEARS] [MONTHS] =
	{
		{68.8, 56.2, 33.4, 32.1, 30.0, 15.2, 6.7, 11.5, 24.8, 36.3, 47.1, 54.3},
		{72.2, 66.9, 43.1, 37.8, 33.7, 26.1, 23.9, 20.1, 34.5, 38.2, 46.9, 50.1},
		{43.1, 40.8, 35.2, 33.6, 28.4, 22.1, 17.9, 27.2, 30.4, 36.1, 40.4, 45.3},
		{52.5, 55.3, 50.2, 26.1, 38.2, 20.1, 4.4, 3.1, 31.1, 33.7, 38.7, 39.0},
		{46.3, 42.0, 33.9, 33.9, 28.0, 26.2, 24.9, 25.7, 25.1, 28.1, 33.7, 39.5}
	};

	//Display annual data table
	printf ("YEAR");
	printf ("\t\t");
	printf ("RAINFALL (INCHES)");
	printf ("\n");

	//Initialise total rainfall across all years
	double all_year_total = 0;

	//Initalise average rainfall across all years
	double all_year_average = 0;

	//Loop through each year and calculate annual rainfall averages
	for (unsigned int i = 0; i < YEARS; ++i)
	{
		//Calculate corresponding calendar year
		unsigned int current_calendar_year = i + (unsigned int) INIT_YEAR;

		//Initialise total for current year
		double current_year_total = 0;
		
		//Loop to accumulate total rainfall for current year
		for (unsigned int j = 0; j < MONTHS; ++j)
		{
			current_year_total += rainfall [i] [j];
		}
		
		//Add current year total to total across all years
		all_year_total += current_year_total;
		
		//Display current year 
		printf ("%i", current_calendar_year);
		printf ("\t\t");
		
		//Display current year total
		printf ("%.1lf", current_year_total);
		printf ("\n");
	}
	
	//Following calculations for each year
	printf ("\n");
	printf ("The yearly average is ");
	
	//Calculate annual average rainfall
	all_year_average = all_year_total / (double) YEARS;
	printf ("%.1lf", all_year_average);
	printf (" inches.");
	printf ("\n");
	printf ("\n");
	
	//Calculate averages by month instead of by year
	printf ("MONTHLY AVERAGES:");
	printf ("\n");
	printf ("\n");

	//Loop through and check if limit for months has been reached and output an additional tab if not. 
	for (unsigned int i = 0; i < (unsigned int) MONTHS; ++i)
	{
		printf ("%s", month_name [i]);
		(i == ((unsigned int) MONTHS - 1) ) ? : printf ("\t");
	}
	printf ("\n");

	//Loop by month in outer loop
	for (unsigned int i = 0; i < (unsigned int) MONTHS; ++i)
	{
		double month_total = 0.0;
		
		//Loop by year in inner loop
		for (unsigned int j = 0; j < (unsigned int) YEARS; ++j)
		{
			//Accrue for specific month across all years
			month_total += rainfall [j] [i];
		}
		//Calculate average across all years for specific month
		double month_average = month_total / (double) YEARS;
		printf ("%.1lf", month_average);
		(i == ((unsigned int) MONTHS - 1) ) ? : printf ("\t");
	}
	printf ("\n");
	printf ("\n");

    return 0;
}
