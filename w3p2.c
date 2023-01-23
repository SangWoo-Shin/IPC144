/*
	==================================================
	Workshop #3 (Part-2): General well-being Log
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
#define LOG_DAYS 3

int main(void)
{
	printf("General Well-being Log\n");
	printf("======================\n");
	const int JAN = 1, DEC = 12;
	int Year, Month, i;
	double morning, evening;
	double Total_morning = 0.0;
	double Total_evening = 0.0;
	double Ave_morning, Ave_evening, Ave_Ova_rate, Ova_total;

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

	for (i = 1; i <= LOG_DAYS; i++)
	{
		switch (Month)
		{
		case 1:
			printf("%d-JAN-0%d\n", Year, i);
			break;
		case 2:
			printf("%d-FEB-0%d\n", Year, i);
			break;
		case 3:
			printf("%d-MAR-0%d\n", Year, i);
			break;
		case 4:
			printf("%d-APR-0%d\n", Year, i);
			break;
		case 5:
			printf("%d-MAY-0%d\n", Year, i);
			break;
		case 6:
			printf("%d-JUN-0%d\n", Year, i);
			break;
		case 7:
			printf("%d-JUL-0%d\n", Year, i);
			break;
		case 8:
			printf("%d-AUG-0%d\n", Year, i);
			break;
		case 9:
			printf("%d-SEP-0%d\n", Year, i);
			break;
		case 10:
			printf("%d-OCT-0%d\n", Year, i);
			break;
		case 11:
			printf("%d-NOV-0%d\n", Year, i);
			break;
		case 12:
			printf("%d-DEC-0%d\n", Year, i);
			break;
		}

		do
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);
			if (morning < 0.0 || morning > 5.0)
				printf("      Error: Rating must be between 0.0 and 5.0 inclusive!\n");
		} while (morning < 0.0 || morning > 5.0);
		Total_morning += morning;
		do
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);
			if (evening < 0.0 || evening > 5.0)
				printf("      Error: Rating must be between 0.0 and 5.0 inclusive!\n");
		} while (evening < 0.0 || evening > 5.0);
		printf("\n");
		Total_evening += evening;
	}
	Ova_total = Total_morning + Total_evening;
	Ave_morning = Total_morning / 3;
	Ave_evening = Total_evening / 3;
	Ave_Ova_rate = (Ave_morning + Ave_evening) / 2;

	printf("Summary\n=======\n");
	printf("Morning total rating: %.3lf\n", Total_morning);
	printf("Evening totla rating: %.3lf\n", Total_evening);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", Ova_total);
	printf("Average morning rating: %.1lf\n", Ave_morning);
	printf("Average evening rating: %.1lf\n----------------------------\n", Ave_evening);
	printf("Average overall rating: %.1lf", Ave_Ova_rate);

	return 0;
}