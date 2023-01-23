// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_

#define _CRT_NO_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"

// ----------------------------------------------------------------------------
// function prototypes
void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const struct Account* accPoint);
void applicationStartup(struct Account account[], int maxElements);
int menuLogin(struct Account account[], int maxElements);
void menuAgent(struct Account account[], int maxElements, const struct Account* login);
int findAccountIndexByAcctNum(int accNo, const struct Account account[], int maxElements, int flag);
void displayAllAccountDetailRecords(const struct Account account[], int maxElements);
void pauseExecution(void);
#endif //!ACCOUNT_TICKETING_UI_H_