// #############################################################################################
//  Assignment: 2
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 30
#define MAX_ID_LENGTH 10
#define PW_LENGTH 8
#define MIN_AGE 18
#define MAX_AGE 110
#include <stdio.h>

#include "commonHelpers.h"

// ----------------------------------------------------------------------------
// structures
struct Person
{
	char name[MAX_LENGTH + 1];
	int birthYear;
	double income;
	char country[MAX_LENGTH + 1];
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
	struct Person person;
	struct UserLogin login;
};
// ----------------------------------------------------------------------------
// function prototypes
void getAccount(struct Account* accPoint);
void getPerson(struct Person* perPoint);
void getUserLogin(struct UserLogin* logPoint);
void updateAccount(struct Account* accPoint);
void updatePerson(struct Person* perPoint);
void updateUserLogin(struct UserLogin* logPoint);
void passwordForm(struct UserLogin* logPoint);
#endif //!ACCOUNT_H_