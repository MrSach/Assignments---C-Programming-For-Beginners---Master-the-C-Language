#include <stdio.h>
#include <stdlib.h>

/*
	Background
		Studied as part of controlling program flow.
		Guided learning exercise: C Programming For Beginners - Master the C Language
		https://www.udemy.com/course/c-programming-for-beginners-/

	Description
		A small program that calculates the week's wages using the information input by the user into the terminal console.
		Basic rate is $12 per hour.
		This applies for the first 40 hours worked.
		The overtime rate is 1.5 times the basic rate and applies after the Basic Rate time threshold has been exceeded.
		Tax bands are also applied to the gross pay, each with their own quantitative thresholds.
		Tax Band 1 applies for the first $300 earned, which is 15%.
		Tax Band 2 applies for the next $150 earned, which is 20%.
		Tax Band 3, which is 25% tax, applies after exceeding the combined gross pay total of $300 + $150, which is $450.
		As can be observed there is a detailed and verbose report for the different data that is calculated from the user's input.
		
		Author
			Sacha

		Date
			2.3.2022
*/

int main()
{
	//assign constant values
	const double basic_rate = 12.0;
	const double overtime_rate = basic_rate * 1.5;
	const int basic_hour_limit = 40;
	const double band_threshold_1 = 300.0;
	const double band_threshold_2 = band_threshold_1 + 150.0;
	const double tax_band_1 = 0.15;
	const double tax_band_2 = 0.2;
	const double tax_band_3 = 0.25;

	//prompt user input for number of hours worked
    	printf ("Enter the number of hours worked as a whole number: ");
    	unsigned int hours_worked = 0;
	scanf ("%i", & hours_worked);

	//check if the hours worked is positive whole number
	if (hours_worked > 0)
	{
		//declares and initialises values for calculations

		//basic hours worked
		unsigned int basic_hours = (hours_worked > basic_hour_limit) ? basic_hour_limit : hours_worked;

		//overtime hours worked
		unsigned int overtime_hours = (hours_worked > basic_hour_limit) ? (hours_worked - basic_hour_limit) : 0;

		//other values, self-explanatory
		double gross_basic_pay = ((double) basic_hours) * basic_rate;
		double gross_overtime_pay = ((double) overtime_hours) * overtime_rate;
		double gross_pay = gross_basic_pay + gross_overtime_pay;

		//declare and initialise taxable pay bands
		double taxable_income_band_1 = 0;
		double taxable_income_band_2 = 0;
		double taxable_income_band_3 = 0;

		//declare and initialise tax to deduct from taxable pay
		double income_tax_band_1 = 0;
		double income_tax_band_2 = 0;
		double income_tax_band_3 = 0;

		//check if gross pay exceeds band 1 threshold
		if (gross_pay > band_threshold_1)
		{
			//assign band 1 taxable income to only band 1 earnings
			taxable_income_band_1 = band_threshold_1;

			//check if gross pay exceeds band 2 threshold
			if (gross_pay > band_threshold_2)
			{
				//assign band 2 taxable income to only band 2 earnings
				taxable_income_band_2 = band_threshold_2 - band_threshold_1;

				//assign band 3 taxable income to only band 3 earnings
				taxable_income_band_3 = gross_pay - band_threshold_2;
			}
			else
			{
				//assign band 2 taxable income to only band 2 earnings
				taxable_income_band_2 = gross_pay - band_threshold_1;
			}
		}
		else
		{
			//gross pay only within taxable band 1, therefore tax entirely at band 1 rate
			taxable_income_band_1 = gross_pay;
		}

		//calculate total taxable income
		double total_taxable_income =
			taxable_income_band_1 + taxable_income_band_2 + taxable_income_band_3;

		//calculate income tax for each band
		income_tax_band_1 = taxable_income_band_1 * tax_band_1;
		income_tax_band_2 = taxable_income_band_2 * tax_band_2;
		income_tax_band_3 = taxable_income_band_3 * tax_band_3;
		double total_income_tax = income_tax_band_1 + income_tax_band_2 + income_tax_band_3;

		//Calculate the net earnings
		double band_1_earnings = taxable_income_band_1 - income_tax_band_1;
		double band_2_earnings = taxable_income_band_2 - income_tax_band_2;
		double band_3_earnings = taxable_income_band_3 - income_tax_band_3;
		double total_earnings = band_1_earnings + band_2_earnings + band_3_earnings;

		//Output the verbose report
		printf ("Hours worked = ");
		printf ("%i", hours_worked);
		printf ("\n");

		printf ("Basic rate = ");
		printf ("%.2lf", basic_rate);
		printf ("\n");

		printf ("Overtime rate = ");
		printf ("%.2lf", overtime_rate);
		printf ("\n");

		printf ("Hours at basic rate = ");
		printf ("%i", basic_hours);
		printf ("\n");

		printf ("Hours at overtime rate = ");
		printf ("%i", overtime_hours);
		printf ("\n");

		printf ("Total Gross Basic Pay = ");
		printf ("%.2lf", gross_basic_pay);
		printf ("\n");

		printf ("Total Gross Overtime Pay = ");
		printf ("%.2lf", gross_overtime_pay);
		printf ("\n");

		printf ("Total Gross Pay = ");
		printf ("%.2lf", gross_pay);
		printf ("\n");

		printf ("Taxable income at Band 1 = ");
		printf ("%.2lf", taxable_income_band_1);
		printf ("\n");

		printf ("Taxable income at Band 2 = ");
		printf ("%.2lf", taxable_income_band_2);
		printf ("\n");

		printf ("Taxable income at Band 3 = ");
		printf ("%.2lf", taxable_income_band_3);
		printf ("\n");

		printf ("Total taxable income = ");
		printf ("%.2lf", total_taxable_income);
		printf ("\n");

		printf ("Tax rate at band 1 = ");
		printf ("%.0lf", tax_band_1 * 100);
		printf ("%%");
		printf ("\n");

		printf ("Tax rate at band 2 = ");
		printf ("%.0lf", tax_band_2 * 100);
		printf ("%%");
		printf ("\n");

		printf ("Tax rate at band 3 = ");
		printf ("%.0lf", tax_band_3 * 100);
		printf ("%%");
		printf ("\n");

		printf ("Income tax at Band 1 = ");
		printf ("%.2lf", income_tax_band_1);
		printf ("\n");

		printf ("Income tax at Band 2 = ");
		printf ("%.2lf", income_tax_band_2);
		printf ("\n");

		printf ("Income tax at Band 3 = ");
		printf ("%.2lf", income_tax_band_3);
		printf ("\n");

		printf ("Total income tax = ");
		printf ("%.2lf", total_income_tax);
		printf ("\n");

		printf ("Earnings at Band 1 = ");
		printf ("%.2lf", band_1_earnings);
		printf ("\n");

		printf ("Earnings at Band 2 = ");
		printf ("%.2lf", band_2_earnings);
		printf ("\n");

		printf ("Earnings at Band 3 = ");
		printf ("%.2lf", band_3_earnings);
		printf ("\n");

		printf ("Total earnings = ");
		printf ("%.2lf", total_earnings);
		printf ("\n");
	}
	else
	{
		//requests criteria from user and rejects value input if not above zero
		printf ("Please enter a positive value for hours worked as a whole number");
		printf ("\n");
	}
    return 0;
}
