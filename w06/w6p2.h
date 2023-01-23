/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : SangWoo,Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_OF_PRODUCT 3
#define NUM_OF_GRAMS 64
#define KG_TO_LBS 2.20462


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

struct ReportData
{
	int sku;
	double price;
	int caloriesPerServ;
	double weightInPound;
	double weightInKG;
	int weightInGram;
	double totalServing;
	double costPerServ;
	double costPerCal;
};
struct ReportData reportData;

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* weightInPound, double* conversionResultKG);

// 9. convert lbs: g
int convertLbsG(const double* weightInPound, int* conversionResultGram);

// 10. convert lbs: kg / g
void convertLbs(const double* weightInPound, double* conversionResultKG, int* conversionResultGram);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeInGram, const int totalGram, double* calResult);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumOfServ, double* calResult);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNumOfCal, double* calResult);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapFlag);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData reportData);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

