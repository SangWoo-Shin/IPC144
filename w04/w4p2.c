/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : SangWoo,Shin
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
	double Income = 0.00, Sum_Cost = 0.00, temptotal = 0.00;
	int prioritySelect, menuSelect, totalMonth, flag = 1;
	int i = 0;
	int Wish_List = 0;
	char Finance[MAX_NUM_OF_ITEM];
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
		if (Wish_List < MIN_NUM_OF_ITEM || Wish_List > MAX_NUM_OF_ITEM)
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
			if (Priority[i] < 1 || Priority[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				flag = 1;
			}
		} while (flag);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &Finance[i]);
			if (Finance[i] == 'y' || Finance[i] == 'n')
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
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Priority[i], Finance[i], ItemCost[i]);
		Sum_Cost += ItemCost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", Sum_Cost);

	do
	{
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &menuSelect);
		printf("\n");
		totalMonth = 0;
		temptotal = 0;
		if (menuSelect < 0 || menuSelect > 2)
		{
			printf("ERROR: Invalid menu selection.\n");
			flag = 1;
		}
		if (menuSelect == 1)
		{
			totalMonth = (int)(Sum_Cost / Income) % 12;
			if ((Sum_Cost / Income) / 12 != (int)(Sum_Cost / Income) / 12)
				totalMonth += 1;

			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", Sum_Cost);
			printf("Forecast: %d years, %d months\n", (int)(Sum_Cost / (12 * Income)), totalMonth);
			for (i = 0; i < Wish_List; i++)
			{
				if (Finance[i] == 'y')
				{
					printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
					i = Wish_List;
				}
			}
			printf("====================================================\n");
			flag = 1;
		}
		if (menuSelect == 2)
		{
			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &prioritySelect);
			printf("\n");
			if (prioritySelect == 1)
			{
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 1)
						temptotal += ItemCost[i];
				}
				totalMonth = (int)(temptotal / Income) % 12;
				if ((temptotal / Income) / 12 != (int)(temptotal / Income) / 12)
					totalMonth += 1;
				printf("====================================================\n");
				printf("Filter:   by priority (1)\n");
				printf("Amount:   $%1.2lf\n", temptotal);
				printf("Forecast: %d years, %d months\n", (int)(temptotal / (12 * Income)), totalMonth);
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 1)
					{
						if (Finance[i] == 'y')
						{
							printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
							i = Wish_List;
						}
					}
				}
				printf("====================================================\n");
				flag = 1;
			}
			if (prioritySelect == 2)
			{
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 2)
						temptotal += ItemCost[i];
				}
				totalMonth = (int)(temptotal / Income) % 12;
				if ((temptotal / Income) / 12 != (int)(temptotal / Income) / 12)
					totalMonth += 1;
				printf("====================================================\n");
				printf("Filter:   by priority (2)\n");
				printf("Amount:   $%1.2lf\n", temptotal);
				printf("Forecast: %d years, %d months\n", (int)(temptotal / (12 * Income)), totalMonth);
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 2)
					{
						if (Finance[i] == 'y')
						{
							printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
							i = Wish_List;
						}
					}
				}
				printf("====================================================\n");
				flag = 1;
			}
			if (prioritySelect == 3)
			{
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 3)
						temptotal += ItemCost[i];
				}
				totalMonth = (int)(temptotal / Income) % 12;
				if ((temptotal / Income) / 12 != (int)(temptotal / Income) / 12)
					totalMonth += 1;
				printf("====================================================\n");
				printf("Filter:   by priority (3)\n");
				printf("Amount:   $%1.2lf\n", temptotal);
				printf("Forecast: %d years, %d months\n", (int)(temptotal / (12 * Income)), totalMonth);
				for (i = 0; i < Wish_List; i++)
				{
					if (Priority[i] == 3)
					{
						if (Finance[i] == 'y')
						{
							printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
							i = Wish_List;
						}
					}
				}
				printf("====================================================\n");
				flag = 1;
			}
			if (prioritySelect < 1 && prioritySelect>3)
			{
				printf("ERROR: Value must be between 1 and 3\n");
				flag = 1;
			}
		}

		if (menuSelect == 0)
		{
		   flag = 0;
		}
	}while (flag);
printf("Best of luck in all your future endeavours!");
return 0;
}