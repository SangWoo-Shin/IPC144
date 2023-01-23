/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Sang Woo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM_OF_PRODUCT 3
#define NUM_OF_GRAMS 64


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	double price;
	int calories;
	double weight;
};
struct CatFoodInfo catFoodInfo;

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* value);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int value);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int value);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);


// 7. Logic entry point
void start(void);
