/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : SangWoo, Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* weightInPound, double* conversionResultKG)
{
	double result;
	if (conversionResultKG == NULL)
	{
		result = *weightInPound / KG_TO_LBS;
		return result;
	}
	else
	{
		*conversionResultKG = *weightInPound / KG_TO_LBS;
		return *conversionResultKG;
	}
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* weightInPound, int* conversionResultGram)
{
	int result;
	if (conversionResultGram == NULL)
	{
		result = (int)(*weightInPound / KG_TO_LBS * 1000);
		return result;
	}
	else
	{
		*conversionResultGram = (int)(*weightInPound / KG_TO_LBS * 1000);
		return *conversionResultGram;
	}
}

// 10. convert lbs: kg and g
void convertLbs(const double* weightInPound, double* conversionResultKG, int* conversionResultGram)
{
	*conversionResultKG = convertLbsKg(weightInPound, conversionResultKG);
	*conversionResultGram = convertLbsG(weightInPound, conversionResultGram);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeInGram, const int totalGram, double* calResult)
{
	double result;
	if (calResult == NULL)
	{
		result = ((double)totalGram / (double)servingSizeInGram);
		return result;	
	}
	else
	{
		*calResult = ((double)totalGram / (double)servingSizeInGram);
		return *calResult;
	}	
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumOfServ, double* calResult)
{
	double result;
	if (calResult == NULL)
	{
		result = (*productPrice) / (*totalNumOfServ);
		return result;
	}
	else
	{
		*calResult = (*productPrice) / (*totalNumOfServ);
		return *calResult;
	}
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNumOfCal, double* calResult)
{
	double result;
	if (calResult == NULL)
	{
		result = (*productPrice) / (*totalNumOfCal);
		return result;
	}
	else
	{
		*calResult = (*productPrice) / (*totalNumOfCal);
		return *calResult;
	}
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo)
{
	double totalNumOfCal;
	reportData.sku = catFoodInfo.sku;
	reportData.caloriesPerServ = catFoodInfo.calories;
	reportData.price = catFoodInfo.price;
	reportData.weightInPound = catFoodInfo.weight;
	convertLbs(&reportData.weightInPound, &reportData.weightInKG, &reportData.weightInGram);
	reportData.totalServing = calculateServings(NUM_OF_GRAMS, reportData.weightInGram, &reportData.totalServing);
	reportData.costPerServ = calculateCostPerServing(&reportData.price, &reportData.totalServing, &reportData.costPerServ);
	totalNumOfCal = (double)reportData.caloriesPerServ * reportData.totalServing;
	reportData.costPerCal = calculateCostPerCal(&reportData.price, &totalNumOfCal, &reportData.costPerCal);

	return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg\n", NUM_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapFlag)
{
	if (cheapFlag != 1)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", reportData.sku, reportData.price, reportData.weightInPound, reportData.weightInKG,
				reportData.weightInGram, reportData.caloriesPerServ, reportData.totalServing, reportData.costPerServ, reportData.costPerCal);
	}
	else if (cheapFlag == 1)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", reportData.sku, reportData.price, reportData.weightInPound, reportData.weightInKG,
		reportData.weightInGram, reportData.caloriesPerServ, reportData.totalServing, reportData.costPerServ, reportData.costPerCal);
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData reportData)
{
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n",reportData.sku, reportData.price );
	printf("Happy shopping!");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i = 0;
	struct CatFoodInfo catFoodInfo[MAX_NUM_OF_PRODUCT] = { {0} };
	struct ReportData reportData[MAX_NUM_OF_PRODUCT] = { {0} };
	int cheapestOption = 0, cheapFlag = 0;

	openingMessage(MAX_NUM_OF_PRODUCT);
	for (i = 0; i < MAX_NUM_OF_PRODUCT; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i + 1);
		reportData[i] = calculateReportData(catFoodInfo[i]);
		if (i != 0 && reportData[i].costPerServ <= reportData[i - 1].costPerServ)
		{
			cheapestOption = i;
		}
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_OF_PRODUCT; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].weight, catFoodInfo[i].calories);
	}
	displayReportHeader();
	for (i = 0; i < MAX_NUM_OF_PRODUCT; i++)
	{
		if (i == cheapestOption)
		{
			cheapFlag = 1;
			displayReportData(reportData[i], cheapFlag);
		}
		if (i != cheapestOption)
		{
			displayReportData(reportData[i], cheapFlag);
		}
		cheapFlag = 0;
	}
	displayFinalAnalysis(reportData[cheapestOption]);
}
