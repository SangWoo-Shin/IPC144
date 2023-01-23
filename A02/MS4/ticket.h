// #############################################################################################
//  Assignment: 2
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#ifndef TICKET_H_
#define TICKET_H_
#define MAX_MESSAGE_LENGTH 150
#define MAX_MESSAGE_STORE 20
#define ACCOUNT_SIZE 15
#define TICKET_SIZE 17
#define MAX_SUBJECT_LINE 30
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "account.h"

struct Message
{
	char accountType;
	char name[MAX_LENGTH + 1];
	char messageDetails[MAX_MESSAGE_LENGTH + 1];
};

struct Ticket
{
	int uniqNum;
	int accNum;
	int statusIndicator;
	char subjectLine[MAX_LENGTH + 1];
	int count;
	struct Message message[MAX_MESSAGE_STORE];
};


void displayTicketDetailHeader(void);
void displayTicketDetailRecord(struct Ticket* tickets, char name[]);
void addNewTicket(struct Ticket* tickets, int accountNumber, char name[]);
int confirmMessage(struct Ticket* tickets, int maxElements, int Indicator);
void manageTicket(int ticketIndex, int accountIndex, struct Ticket* tickets, char customerName[], char agentName[]);
int checkMessageBox(int ticketIndex, struct Ticket* tickets, int maxElements);
int checkTicketBox(int accountIndex, char accountType, struct Ticket* tickets, int maxElements);
int findTicketIndexThroughTicketNum(struct Ticket* tickets, int maxElements);
int loadTickets(struct Ticket* tickets, int maxElements);
#endif //!TICKET_H_