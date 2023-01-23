/*
	==================================================
	Workshop #2 (Part-1): Change Maker Machine
	==================================================
	Name   : SangWoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double value;
	int Toonies, Loonies, Quaters;
	double remaining = 0.00;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &value);
	printf("\n");
	
	if (value >= 2.00)
	{
		Toonies = value / 2;
		remaining = value -(2*Toonies);
		printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", Toonies, remaining);
	}
	if (remaining >= 1.00)
	{
		Loonies = remaining / 1.00;
		remaining = remaining - (Loonies*1);
		printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", Loonies, remaining);
	}
	if (remaining >= 0.25)
	{
		Quaters = remaining / 0.25;
		remaining = remaining - (Quaters*0.25);
		printf("$0.25 Quarters X %d (remaining: $%.2lf)\n\n", Quaters, remaining);
	}
	printf("Machine error! Thank you for letting me keep $%.2lf!", remaining);
	return 0;
}

