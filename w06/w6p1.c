/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :  Sang Woo Shin
	ID     :  119294213
	Email  :  sshin36@myseneca.ca
	Section:  NFF
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value)
{
	int IntTest = 0;
	while (IntTest <= 0)
	{
		scanf("%d", &IntTest);
		if (IntTest <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	if (value != NULL)
	{
		*value = IntTest;
		return *value;
	}
	return IntTest;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* value)
{
	double DoubleTest = 0;
	while (DoubleTest <= 0)
	{
		scanf("%lf", &DoubleTest);
		if (DoubleTest <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	if (value != NULL)
	{
		*value = DoubleTest;
		return *value;
	}
	return DoubleTest;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int Num_Of_Products)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_OF_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n", NUM_OF_GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int  Seq_Num_Of_Products)
{
	printf("\nCat Food Product #%d\n", Seq_Num_Of_Products);
	printf("--------------------\n");
	printf("SKU           : ");
	catFoodInfo.sku = getIntPositive(&catFoodInfo.sku);
	printf("PRICE         : $");
	catFoodInfo.price = getDoublePositive(&catFoodInfo.price);
	printf("WEIGHT (LBS)  : ");
	catFoodInfo.weight = getDoublePositive(&catFoodInfo.weight);
	printf("CALORIES/SERV.: ");
	catFoodInfo.calories = getIntPositive(&catFoodInfo.calories);

	return catFoodInfo;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// 7. Logic entry point
void start(void)
{
	int i = 0;
	struct CatFoodInfo catFoodInfo[MAX_NUM_OF_PRODUCT] = { {0} };

	openingMessage(MAX_NUM_OF_PRODUCT);
	for (i = 0; i < MAX_NUM_OF_PRODUCT; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_OF_PRODUCT; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].weight, catFoodInfo[i].calories);
	}
}
