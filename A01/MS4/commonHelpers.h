// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ----------------------------------------------------------------------------
// function prototypes
int currentYear(void);
void clearStandardInputBuffer(void);
int getInteger(void);
int getPositiveInteger(void);
double getPositiveDouble(void);
int getIntFromRange(int lowerBound, int upperBound);
char getCharOption(const char name[]);
void getCString(char* cString, int lowerBound, int upperBound);

#endif // !COMMON_HELPERS_H_