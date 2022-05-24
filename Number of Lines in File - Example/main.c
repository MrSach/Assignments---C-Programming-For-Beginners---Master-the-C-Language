#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*

	Description
		Reads a predefined file into the program, and outputs the number of lines to the output stream
	Author
		Sacha
	Date
		11.3.2022

*/

int main()
{
	FILE * pfile = NULL;
	pfile = fopen ("testfile.txt", "r");
	if (pfile == NULL)
	{
		return -2;
	}
	size_t count = 0;
	for (size_t ch = fgetc (pfile); ch != EOF; ch = fgetc (pfile))
	{
		if (ch == '\n')
		{
			++count;
		}
	}
	printf ("\n%li\n", count);
	fclose (pfile);
	pfile = NULL;
    return 0;
}
