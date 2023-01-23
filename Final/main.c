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
#include <stdio.h>
#include "productData.h"



int readSalesFile(FILE* fp, struct ProductSalesList* prodList, struct DailySalesList* dailySales)
{
    int numberSalesRead = 0, valuesRead;
    struct SingleSaleRecord saleRec = { {0} };
    char productName[MAX_PRODUCT_NAME_LEN];

    while (!feof(fp))
    {
        valuesRead = fscanf(fp, "%[^/]/%d/%lf/%d/%d/%d%*c",
            productName, &saleRec.numberSold, &saleRec.salePrice,
            &saleRec.saleDate.month, &saleRec.saleDate.day,
            &saleRec.saleDate.year);
        if (valuesRead > 0)
        {
            addSale(prodList, dailySales, productName, &saleRec);
            numberSalesRead++;
        }
    }
    return numberSalesRead;
}
int main(void)
{
    int salesRead = 0;
    struct ProductSalesList prodList[MAX_PRODUCTS] = { {0} };
    struct DailySalesList dailySales[MAX_DAYS] = { {0} };
    FILE* fp;
    fp = fopen("salesData.txt", "r");
    if (fp != NULL) {
        salesRead = readSalesFile(fp, prodList, dailySales);
        fclose(fp);
    }
    printf("***** Seneca Gardens *****\n");
    salesInfoUI(prodList, dailySales, salesRead);
    return 0;
}

