// ############################################################################################
//  Assignment: 2
//  Milestone : 2
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "accountTicketingUI.h"
#include "ticket.h"

void displayTicketDetailHeader(void)
{
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
}

void displayTicketDetailRecord(struct Ticket* tickets, char name[])
{
	printf("%06d %05d %-15s %5s %-30s     %d\n", tickets->uniqNum, tickets->accNum, name,
		tickets->statusIndicator == 1 ? "ACTIVE" : "CLOSED", tickets->subjectLine, tickets->count);
}

void addNewTicket(struct Ticket* tickets ,int accountNumber, char name[])
{
	int i = 0;
	int idx = 0, bigNum = 0;
	for (i = 0; i < TICKET_SIZE; i++)
	{
		if (tickets[i].uniqNum == '\0')
		{
			tickets[i].accNum = accountNumber;
			tickets[i].count = 0;
			idx = i;
			break;
		}
	}
	for (i = 0; i < TICKET_SIZE; i++)
	{
		if (tickets[i].uniqNum > 0)
		{
			if (bigNum < tickets[i].uniqNum)
			{
				bigNum = tickets[i].uniqNum;
			}
		}
	}
	tickets[idx].uniqNum = bigNum + 1;
	printf("\nNew Ticket (Ticket#:%06d)\n", tickets[idx].uniqNum);
	printf("----------------------------------------\n");
	printf("Enter the ticket SUBJECT (%d chars. maximum): ", MAX_SUBJECT_LINE);
	getCString(tickets[idx].subjectLine, 1, MAX_SUBJECT_LINE);
	printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
	getCString(tickets[idx].message->messageDetails, 1, MAX_MESSAGE_LENGTH);
	strcpy(tickets[idx].message->name, name);
	tickets[idx].count++;
	printf("\n*** New ticket created! ***\n\n");
	pauseExecution();
}

int confirmMessage(struct Ticket* tickets, int maxElements, int Indicator)
{
	int choice = 1, i, j;
	printf("Enter the ticket number to view the messages or\n");
	printf("0 to return to previous menu: ");
	scanf("%d", &choice);
	if (choice == 0)
	{
		printf("\n");
	}
	else
	{
		for (i = 0; i < maxElements; i++)
		{
			if (tickets[i].statusIndicator == Indicator && tickets[i].count > 0)
			{
				if (choice == tickets[i].uniqNum)
				{
					printf("\n================================================================================\n");
					printf("%06d (%5s) Re: %s\n", tickets[i].uniqNum, tickets[i].statusIndicator == 1 ? "ACTIVE" : "CLOSED",
						tickets[i].subjectLine);
					printf("================================================================================\n");
					for (j = 0; j < tickets[i].count; j++)
					{
						printf("%s (%s):\n", tickets[i].message[j].accountType == 'A' ? "AGENT" : "CUSTOMER", tickets[i].message[j].name);
						printf("   %s\n\n", tickets[i].message[j].messageDetails);
					}
					break;
				}
			}
			else if (i + 1 == maxElements)
			{
				printf("\nERROR: Invalid ticket number.\n\n");
			}
		}
		clearStandardInputBuffer();
		pauseExecution();
	}
	return choice;
}

void manageTicket(int ticketIndex, int accountIndex, struct Ticket* tickets, char customerName[], char agentName[])
{
	int messageIndex = 0, selection, flag = 0;
	char intention;

	if (ticketIndex == -1)
	{
		printf("ERROR: Invalid ticket number.\n");
	}
	else
	{
		do
		{
			printf("\n----------------------------------------\n");
			printf("Ticket %06d - Update Options\n", tickets[ticketIndex].uniqNum);
			printf("----------------------------------------\n");
			printf("Status  : %s\n", tickets[ticketIndex].statusIndicator == 1 ? "ACTIVE" : "CLOSED");
			printf("Subject : %s\n", tickets[ticketIndex].subjectLine);
			printf("Acct#   : %d\n", tickets[ticketIndex].accNum);
			printf("Customer: %s\n", customerName);
			printf("----------------------------------------\n");
			printf("1) Add CUSTOMER message\n");
			printf("2) Add AGENT message\n");
			printf("3) Close ticket\n");
			printf("4) Re-activate ticket\n");
			printf("0) Done\n");
			printf("Selection: ");
			selection = getIntFromRange(0, 4);
			if (selection == 1)
			{
				messageIndex = tickets[ticketIndex].count;
				flag = checkMessageBox(ticketIndex, tickets, MAX_MESSAGE_STORE);
				if (flag != -1)
				{
					printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
					getCString(tickets[ticketIndex].message[messageIndex].messageDetails, 1, MAX_MESSAGE_LENGTH);
					strcpy(tickets[ticketIndex].message[messageIndex].name, customerName);
					tickets[ticketIndex].message[messageIndex].accountType = 'C';
					tickets[ticketIndex].count++;
				}
			}
			else if (selection == 2)
			{
				messageIndex = tickets[ticketIndex].count;
				flag = checkMessageBox(ticketIndex, tickets, MAX_MESSAGE_STORE);
				if (flag != -1)
				{
					printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
					getCString(tickets[ticketIndex].message[messageIndex].messageDetails, 1, MAX_MESSAGE_LENGTH);
					strcpy(tickets[ticketIndex].message[messageIndex].name, agentName);
					tickets[ticketIndex].message[messageIndex].accountType = 'A';
					tickets[ticketIndex].count++;
				}
			}
			else if (selection == 3)
			{
				if (tickets[ticketIndex].statusIndicator == 0)
				{
					printf("\nERROR: Ticket is already closed!\n");
				}
				else
				{
					printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
					intention = getCharOption("yYnN");
					if (intention == 'y' || intention == 'Y')
					{
						tickets[ticketIndex].statusIndicator = 0;
						printf("\n*** Ticket closed! ***\n");
					}
				}
			}
			else if (selection == 4)
			{
				if (tickets[ticketIndex].statusIndicator == 1)
				{
					printf("\nERROR: Ticket is already active!\n");
				}
				else
				{
					printf("\nAre you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
					intention = getCharOption("yYnN");
					if (intention == 'y' || intention == 'Y')
					{
						tickets[ticketIndex].statusIndicator = 1;
						printf("\n*** Ticket re-activated! ***\n");
					}
				}
			}
			else
			{
				printf("\n");
			}
		} while (selection != 0);
	}
}

int checkMessageBox(int ticketIndex, struct Ticket* tickets, int maxElements)
{
	int flag = 0;

	if (tickets[ticketIndex].statusIndicator == 0)
	{
		flag = -1;
		printf("\nERROR: Ticket is closed - new messages are not permitted.\n\n");
		pauseExecution();
	}
	else if (tickets[ticketIndex].count == maxElements)
	{

		flag = -1;
		printf("\nERROR: Message limit has been reached, call ITS Support!\n\n");
		pauseExecution();
	}
	else
	{
		flag = 1;
	}

	return flag;
}

int checkTicketBox(int accountIndex, char accountType, struct Ticket* tickets, int maxElements)
{
	int i, flag = 0;
	if (accountType == 'A')
	{
		printf("\nERROR: Agent accounts can't have tickets!\n\n");
		pauseExecution();
	}
	else
	{
		for (i = 0; i < maxElements; i++)
		{
			if (tickets[i].uniqNum == '\0')
			{
				flag = 1;
				break;
			}
			else if (i + 1 == maxElements)
			{
				printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
				pauseExecution();
			}
		}
	}
	return flag;
}

int findTicketIndexThroughTicketNum(struct Ticket* tickets, int maxElements)
{
	int ticketNum, i, index = -1;
	printf("\nEnter ticket number: ");
	scanf("%d", &ticketNum);
	for (i = 0; i < maxElements; i++)
	{
		if (ticketNum == tickets[i].uniqNum)
		{
			index = i;
			break;
		}
	}
	return index;
}