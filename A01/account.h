//==================================
//  Assignments #1 Milestone #2
//  Name: Sang Woo Shin
//  ID: 119294213
//  Email: sshin36@myseneca.ca
//  Section: NFF
//===================================

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 30
#define MAX_ID_LENGTH 10
#define PW_LENGTH 8
#define MIN_AGE 18
#define MAX_AGE 110
#include <stdio.h>

struct Person
{
	char name[MAX_LENGTH +1];
	int birthYear;
	double income;
	char country[MAX_LENGTH +1];
};
struct UserLogin
{
	char ID[MAX_ID_LENGTH + 1];
	char password[PW_LENGTH + 1];
};
struct Account
{
	int accountNumber;
	char accountType;
};

