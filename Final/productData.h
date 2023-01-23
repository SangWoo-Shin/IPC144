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
#ifndef _PRODUCT_DATA_H_
#define _PRODUCT_DATA_H_

#define MAX_PRODUCT_NAME_LEN 30
#define MAX_PRODUCTS 20
#define MAX_DAYS 365


// *** DATA TYPES ***
// 
// This struct is to hold date information
struct SaleDate {
    int day;
    int month;
    int year;
};

//This struct is to hold the information of one transaction
struct SingleSaleRecord {
    char productName[MAX_PRODUCT_NAME_LEN + 1];
    struct SaleDate saleDate;
    int numberSold;
    double salePrice;
};

//This struct is to contain Product Sales information 
struct ProductSalesList {
    char productName[MAX_PRODUCT_NAME_LEN + 1];
    double price;
    int numSold;
};

//This is struct is to contain Daily Sales information
struct DailySalesList {
    struct SingleSaleRecord saleRec[MAX_PRODUCTS];
};


// *** FUNCTIONS ***

//adding sales to respective structs 
void addSale(struct ProductSalesList* prodList, struct DailySalesList* dailySales,
    char productName[MAX_PRODUCT_NAME_LEN], struct SingleSaleRecord* saleRec);


// *** HELPER FUNCTIONS *** 

//Prototype revenue calculator 
//WORKS INSIDE OF printf() -- for example: SEE PRODUCTDATA.C LINE 115 - 116 ***
//Revenue data need not be stored as a variable globally
double calculateRevenue(double price, int numSold);

//sales display UI for related sales information
void salesInfoUI(struct ProductSalesList* prodList, struct DailySalesList* dailySales, int salesRead);

// Function to view all sales for menu option 1 
void displayAllSales(struct DailySalesList* dailySales, int salesRead);

// Showing details of product sale sorted by product name for menu option 2 
void displaySalesByProduct(struct ProductSalesList* prodList, int salesRead);

// Sorting daily sale on the descending order of revenue and showing them for menu option 3
void displaySalesByRevenue(struct DailySalesList* dailySales, int salesRead);

// This function checks and assures that the entered integer is within the given range. 
int getIntFromRange(int lowerBound, int upperBound);

#endif //_PRODUCT_DATA_H_