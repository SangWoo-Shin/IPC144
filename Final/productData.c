/*
	Final Project
	==================================================
	Student #1
	==================================================
	Name   : Furkan Veli Ozalp
	ID     : 157580200
	Email  : fvozalp@myseneca.ca
	Section: NFF

	==================================================
	Student #2
	==================================================
	Name   : SangWoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF

	==================================================
	Student #3
	==================================================
	Name   : Kristjan Punno
	ID     : 150695211
	Email  : kpunno@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include "productData.h"
#include <stdio.h>
#include <string.h>

void addSale(struct ProductSalesList* prodList, struct DailySalesList* dailySales,
	char productName[MAX_PRODUCT_NAME_LEN], struct SingleSaleRecord* saleRec)
{
	int i, j, found;
	i = j = found = 0;

	for (i = 0; i < MAX_PRODUCTS && (!found); i++) {
		if (strcmp(prodList[i].productName, productName) == 0) {
			found = 1;
			prodList[i].numSold += saleRec->numberSold;
			prodList[i].price = saleRec->salePrice;
		}
		else if (strcmp(prodList[i].productName, "") == 0) {
			strcpy(prodList[i].productName, productName);
			found = 1;
			prodList[i].numSold += saleRec->numberSold;
			prodList[i].price = saleRec->salePrice;
		}
	}
	if (!found)
		printf("Oops! Something went wrong! Call tech help!");

	for (i = 0, j = 0, found = 0; i < MAX_PRODUCTS && (!found);) {
		if ((dailySales[i].saleRec[j].saleDate.day == saleRec->saleDate.day)
			&& (dailySales[i].saleRec[j].saleDate.month == saleRec->saleDate.month)
			&& (dailySales[i].saleRec[j].saleDate.year == saleRec->saleDate.year))
		{
			found = 1;
		}
		else if ((dailySales[i].saleRec[j].saleDate.day == 0)
			&& (dailySales[i].saleRec[j].saleDate.month == 0)
			&& (dailySales[i].saleRec[j].saleDate.year == 0))
		{
			found = 1;
		}
		else
			i++;
	}
	if (found) {
		for (j = 0, found = 0; (j < MAX_PRODUCTS) && !found; j++) {
			if (strcmp(dailySales[i].saleRec[j].productName, "") == 0) {
				strcpy(dailySales[i].saleRec[j].productName, productName);
				dailySales[i].saleRec[j].saleDate = saleRec->saleDate;
				dailySales[i].saleRec[j].numberSold = saleRec->numberSold;
				dailySales[i].saleRec[j].salePrice = saleRec->salePrice;
				found = 1;
			}
		}
	}
	else
		printf("Oops! Something went wrong! Call tech help!");
}

void displayAllSales(struct DailySalesList* dailySales, int salesRead)
{
	struct SingleSaleRecord singleSale[MAX_PRODUCTS] = { {{0} } };
	struct SingleSaleRecord temp = { {0} };

	int done = 0;
	int i, j, k;
	int count = 1;
	printf("DAY MONTH YEAR               PRODUCT   #SOLD   PRICE\n");
	i = j = k = 0;
	for (i = 0; i < salesRead - 1; i++)
	{
		for (j = 0; dailySales[i].saleRec[j].numberSold != 0; j++)
		{
			singleSale[k] = dailySales[i].saleRec[j];
			k++;
		}
	}
	i = 0;
	while (i < salesRead - 1) {
		done = 0;
		count = 1;
		for (j = i + 1; j < salesRead - 1 && done == 0; j++) {
			if (strcmp(singleSale[j].productName, singleSale[i].productName) == 0) {
				k = i + 1;
				temp = singleSale[j];
				while (k < j) {
					singleSale[j] = singleSale[j - 1];
					j--;
					count++;
				}
				singleSale[i + 1] = temp;
				done = 1;
			}
		}
		i += count;
	}
	for (i = 0; i < salesRead; i++) {
		printf(" %02d    %02d %4d  %20s  %6d  %6.2lf\n", singleSale[i].saleDate.day,
			singleSale[i].saleDate.month, singleSale[i].saleDate.year,
			singleSale[i].productName, singleSale[i].numberSold,
			singleSale[i].salePrice);
	}
	printf("\n");
}

void displaySalesByProduct(struct ProductSalesList* prodList, int salesRead)
{

	printf("PRODUCT               #SOLD     REVENUE\n");

	int i = 0;
	for (i = 0; i < salesRead - 1; i++) {
		printf("%-20s  %5d   %9.2lf\n", prodList[i].productName, prodList[i].numSold,
			calculateRevenue(prodList[i].price, prodList[i].numSold));
	}
	printf("\n");
}

void displaySalesByRevenue(struct DailySalesList* dailySales, int salesRead)
{
	int i = 0, j = 0;
	double revenue = 0.0;
	double dailyRevenue[MAX_PRODUCTS] = { 0.0 };
	for (i = 0; i < salesRead - 1; i++)
	{
		for (j = 0; strcmp(dailySales[i].saleRec[j].productName, "") != 0; j++)
		{
			revenue = calculateRevenue(dailySales[i].saleRec[j].salePrice, dailySales[i].saleRec[j].numberSold);
			dailyRevenue[i] += revenue;
		}
		j = 0;
	}
	for (i = 0; dailyRevenue[i] != '\0'; i++)
	{
		int m = i;
		revenue = 0;
		for (j = i + 1; dailyRevenue[j] != '\0'; j++)
		{
			if (dailyRevenue[m] < dailyRevenue[j])
			{
				m = j;
			}
		}
		if (m != i)
		{
			revenue = dailyRevenue[i];
			dailyRevenue[i] = dailyRevenue[m];
			dailyRevenue[m] = revenue;
		}
	}

	printf("   REVENUE  DAY  MONTH  YEAR\n");

	for (i = 0; dailyRevenue[i] != '\0'; i++)
	{
		printf(" %9.2lf   %02d     %02d  %4d\n", dailyRevenue[i],
			dailySales[i].saleRec->saleDate.day, dailySales[i].saleRec->saleDate.month, dailySales[i].saleRec->saleDate.year);
	}
	printf("\n");
}


double calculateRevenue(double price, int numSold)
{
	double revenue = price * numSold;
	return revenue;
}

void salesInfoUI(struct ProductSalesList* prodList, struct DailySalesList* dailySales, int salesRead)
{
	int selection;
	do {
		printf("Select one of the Following Options:\n");
		printf("1-View All Sales\n");
		printf("2-View Sales By Product\n");
		printf("3-View Sales by Date sorted by revenue\n");
		printf("0-Exit\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		putchar('\n');
		switch (selection) {
		case 0:
			printf("Goodbye!");
			break;
		case 1:
			displayAllSales(dailySales, salesRead);
			break;
		case 2:
			displaySalesByProduct(prodList, salesRead);
			break;
		case 3:
			displaySalesByRevenue(dailySales, salesRead);
			break;
		default:
			printf("Oops! Something went wrong! Call tech help!");
		}
	} while (selection != 0);
}


int getIntFromRange(int lowerBound, int upperBound)
{
	while (1)
	{
		int intValue = 0;
		char newLine = 'x';
		scanf("%d%c", &intValue, &newLine);
		if (intValue % 1 == 0 && newLine == '\n')
		{
			if (intValue >= lowerBound && intValue <= upperBound)
			{
				return intValue;
			}
			else
			{
				printf("Enter a valid integer between %d and %d: ", lowerBound, upperBound);
			}
		}
		else if (newLine != '\n')
		{
			while (getchar() != '\n')
			{
				; // On purpose: do nothing
			}
			printf("ERROR: Value must be an integer: ");
		}
	}
}
