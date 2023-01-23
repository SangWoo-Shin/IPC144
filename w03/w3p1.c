/*
	==================================================
	Workshop #3 (Part-1): General well-being Log
	==================================================
	Name   : Sang Woo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void)
{
	printf("General Well-being Log\n");
	printf("======================\n");
	const int JAN = 1, DEC = 12;
	int Year, Month;

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &Year, &Month);
		if (Year < MIN_YEAR || Year > MAX_YEAR)
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		if (Month < JAN || Month > DEC)
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
	} while (Year < MIN_YEAR || Year > MAX_YEAR || Month < JAN || Month > DEC);

	printf("\n*** Log date set! ***\n\n");


	if (Month == 1)
		printf("Log starting date: %d-JAN-01", Year);

	if (Month == 2)
		printf("Log starting date: %d-FEB-01", Year);

	if (Month == 3)
		printf("Log starting date: %d-MAR-01", Year);

	if (Month == 4)
		printf("Log starting date: %d-APR-01", Year);

	if (Month == 5)
		printf("Log starting date: %d-MAY-01", Year);

	if (Month == 6)
		printf("Log starting date: %d-JUN-01", Year);

	if (Month == 7)
		printf("Log starting date: %d-JUL-01", Year);

	if (Month == 8)
		printf("Log starting date: %d-AUG-01", Year);

	if (Month == 9)
		printf("Log starting date: %d-SEP-01", Year);

	if (Month == 10)
		printf("Log starting date: %d-OCT-01", Year);

	if (Month == 11)
		printf("Log starting date: %d-NOV-01", Year);

	if (Month == 12)
		printf("Log starting date: %d-DEC-01", Year);



	return 0;
}