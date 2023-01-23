// #############################################################################################
//  Assignment: 2
//  Milestone : 2
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "account.h"
#include "ticket.h"

struct AccountTicketingData
{
	struct Account* accounts;
	const int ACCOUNT_MAX_SIZE;

	struct Ticket* tickets;
	const int TICKET_MAX_SIZE;
};

// ----------------------------------------------------------------------------
// function prototypes
void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const struct Account* accPoint);
void applicationStartup(struct  AccountTicketingData* data);
int menuLogin(struct Account account[], int maxElements);
void menuAgent(struct AccountTicketingData* data, const struct Account* login);
int findAccountIndexByAcctNum(int accNo, const struct Account account[], int maxElements, int flag);
void displayAllAccountDetailRecords(const struct Account account[], int maxElements);
void pauseExecution(void);
int findAccountIndexThroughTicketIndex(int ticketIndex, struct AccountTicketingData* data, int maxElements);
void displaySpecificTicketDetailRecords(struct AccountTicketingData* data, int maxElements, int Indicator, int flag);
void removeAccount(struct AccountTicketingData* data, int maxElements, int loginAccNum);
#endif //!ACCOUNT_TICKETING_UI_H_