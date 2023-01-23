/*
	==================================================
	Workshop #2 (Part-2): Change Maker Machine
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
	double value, service, Rvalue;
	int Toonies, Loonies, Quaters, Dime, Nickel, Penny;
	int Rounding, Remaining, intBalance, intService, intRvalue, intRemaining;
	
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &value);
	intBalance = value * 100;
	intService = intBalance * 5;
	if (intService % 100 >= 50)
	{
		Remaining = intService % 100;
		Rounding = 100 - Remaining;
		intService += Rounding;
		service = (double)intService / 10000;
		Rvalue = value - service;
	}
	else if (intService % 100 < 50)
	{
		Remaining = intService % 100;
		intService -= Remaining;
		service = (double)intService / 10000;
		Rvalue = value - service;
	}
	intRvalue = Rvalue * 100;
	printf("Service fee (5.0 percent): %.2lf\n", service);
	printf("Balance to dispense: $%.2lf\n\n", Rvalue);

	if (intRvalue >= 200)
	{
		Toonies = intRvalue / 200;
		intRemaining = intRvalue - (200 * Toonies);
		printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", Toonies, (double)intRemaining/100);
	}
	if (intRemaining >= 100)
	{
		Loonies = intRemaining / 100;
		intRemaining = intRemaining - (Loonies * 100);
		printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", Loonies, (double)intRemaining/100);
	}
	if (intRemaining >= 25)
	{
	    Quaters = intRemaining / 25;
		intRemaining = intRemaining - (Quaters*25);
		printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", Quaters, (double)intRemaining/100);
	}
	if (intRemaining >= 10)
	{
		Dime = intRemaining / 10;
		intRemaining = intRemaining - (Dime * 10);
		printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", Dime, (double)intRemaining/100);
	}
	if (intRemaining >= 5)
	{
		Nickel = intRemaining / 5;
		intRemaining = intRemaining - (Nickel * 5);
		printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", Nickel, (double)intRemaining/100);
	}
	if (intRemaining >= 1)
	{
 		Penny = intRemaining/1;
		intRemaining = intRemaining - (Penny * 1);
		printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n\n", Penny, (double)intRemaining/100);
	}
	printf("All coins dispensed!");
	return 0;
}