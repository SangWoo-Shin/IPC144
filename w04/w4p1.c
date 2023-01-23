/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Sang Woo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_OF_ITEM 10
#define MIN_NUM_OF_ITEM 1

#include <stdio.h>


int main(void)
{
	const double I_Minimum = 500.00, I_Maximum = 400000.00, C_Minimum = 100.00;
	double Income = 0.00, Sum_Cost = 0.00;
	int flag = 1;
	int i = 0;
	int Wish_List = 0;
	char Financed[MAX_NUM_OF_ITEM];
	double ItemCost[MAX_NUM_OF_ITEM];
	int Priority[MAX_NUM_OF_ITEM];
	printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n\n");

	do
	{
		flag = 0;
		printf("Enter your monthly NET income: $");
		scanf("%lf", &Income);
		if (Income < I_Minimum)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
			flag = 1;
		}
		if (Income > I_Maximum)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
			flag = 1;
		}
	} while (flag);
	printf("\n");
	do
	{
		flag = 0;
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &Wish_List);
		if (Wish_List < MIN_NUM_OF_ITEM)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
			flag = 1;
		}
		if (Wish_List > MAX_NUM_OF_ITEM)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
			flag = 1;
		}
	} while (flag);

	for (i = 0; i < Wish_List; i++)
	{
		printf("\n");
		printf("Item-%d Details:\n", i + 1);
		do
		{
			flag = 0;
			printf("   Item cost: $");
			scanf("%lf", &ItemCost[i]);
			if (ItemCost[i] < C_Minimum)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
				flag = 1;
			}
		} while (flag);

		do
		{
			flag = 0;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &Priority[i]);
			if (Priority[i] < 1)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				flag = 1;
			}
			if (Priority[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				flag = 1;
			}
		} while (flag);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &Financed[i]);
			if (Financed[i] == 'y' || Financed[i] == 'n')
				flag = 0;
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				flag = 1;
			}
		} while (flag);

	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < Wish_List; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Priority[i], Financed[i], ItemCost[i]);
		Sum_Cost += ItemCost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", Sum_Cost);
	printf("Best of luck in all your future endeavours!");
	return 0;
}
