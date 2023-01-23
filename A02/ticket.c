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
#include "commonHelpers.h"
#include "account.h"
#include "ticket.h"

void displayTicketDetailHeader(void)
{
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
}

void displayTicketDetailRecord(struct Ticket* tickets, struct Account* accounts)
{
	printf("%06d %05d %-15s %5s %-30s     %d\n", tickets->uniqNum, tickets->accNum, accounts->person.name,
		tickets->statusIndicator == 1 ? "ACTIVE" : "CLOSED", tickets->subjectLine, tickets->count);
}

void  displaySpecificTicketDetailRecords(struct AccountTicketingData* data, int maxElements, int Indicator, int flag)
{
	int i, choice = 0, accIdx;
	do
	{
		displayTicketDetailHeader();
		if (flag == 0) // New ticket
		{
			for (i = 0; i < maxElements; i++)
			{
				if (data->tickets[i].statusIndicator == Indicator && data->tickets[i].count == 1)
				{
					accIdx = findAccountIndexThroughTicketIndex(i, data, ACCOUNT_SIZE);
					displayTicketDetailRecord(&data->tickets[i], &data->accounts[accIdx]);
				}
			}
			printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
			choice = confirmMessage(data, maxElements, Indicator);
		}
		else if (flag == 1) // Active ticket or Closed ticket
		{
			for (i = 0; i < maxElements; i++)
			{
				if (data->tickets[i].statusIndicator == Indicator && data->tickets[i].count > 0)
				{
					accIdx = findAccountIndexThroughTicketIndex(i, data, ACCOUNT_SIZE);
					displayTicketDetailRecord(&data->tickets[i], &data->accounts[accIdx]);
				}
			}
			printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
			choice = confirmMessage(data, maxElements, Indicator);
		}
	} while (choice != 0);
}


void addNewTicket(struct AccountTicketingData* data)
{
	int accountIndex = 0, i = 0 ,flag = 0;
	char intention;
	accountIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
	flag = checkTicketBox(accountIndex, data, TICKET_SIZE);
	if (flag == 1)
	{
			printf("\n");
			displayAccountDetailHeader();
			displayAccountDetailRecord(&data->accounts[accountIndex]);
			printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
			intention = getCharOption("yYnN");
			if (intention == 'y' || intention == 'Y')
			{
				int idx = 0, bigNum = 0;
				for (i = 0; i < TICKET_SIZE; i++)
				{
					if (data->tickets[i].uniqNum == '\0')
					{
						data->tickets[i].accNum = data->accounts[accountIndex].accountNumber;
						data->tickets[i].count = 0;
						idx = i;
						break;
					}
				}
				for (i = 0; i < TICKET_SIZE; i++)
				{
					if (data->tickets[i].uniqNum > 0)
					{
						if (bigNum < data->tickets[i].uniqNum)
						{
							bigNum = data->tickets[i].uniqNum;
						}
					}
				}
				data->tickets[idx].uniqNum = bigNum + 1;
				printf("\nNew Ticket (Ticket#:%06d)\n", data->tickets[idx].uniqNum);
				printf("----------------------------------------\n");
				printf("Enter the ticket SUBJECT (%d chars. maximum): ", MAX_SUBJECT_LINE);
				getCString(data->tickets[idx].subjectLine, 1, MAX_SUBJECT_LINE);
				printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
				getCString(data->tickets[idx].message[0].messageDetails, 1, MAX_MESSAGE_LENGTH);
				strcpy(data->tickets[idx].message[0].name ,data->accounts[accountIndex].person.name);
				data->tickets[idx].count++;
				printf("\n*** New ticket created! ***\n\n");
				pauseExecution();
			}
	}
}

int confirmMessage(struct AccountTicketingData* data, int maxElements, int Indicator)
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
			if (data->tickets[i].statusIndicator == Indicator && data->tickets[i].count > 0)
			{
				if (choice == data->tickets[i].uniqNum)
				{
					printf("\n================================================================================\n");
					printf("%06d (%5s) Re: %s\n", data->tickets[i].uniqNum, data->tickets[i].statusIndicator == 1 ? "ACTIVE" : "CLOSED",
						data->tickets[i].subjectLine);
					printf("================================================================================\n");
					for (j = 0; j < data->tickets[i].count; j++)
					{
						printf("%-9s(%s):\n", data->tickets[i].message[j].accountType == 'A' ? "AGENT" : "CUSTOMER", data->tickets[i].message[j].name);
						printf("   %s\n\n", data->tickets[i].message[j].messageDetails);
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


int findTicketIndexThroughTicketNum(struct AccountTicketingData* data, int maxElements)
{
	int ticketNum, i, index = 0;
	printf("\nEnter ticket number: ");
	scanf("%d", &ticketNum);
	for (i = 0; i < maxElements; i++)
	{
		if (ticketNum == data->tickets[i].uniqNum)
		{
			index = i;
			break;
		}
		else if (i + 1 == maxElements)
		{
			index = -1;
		}
	}
	return index;
}

int findAccountIndexThroughTicketIndex(int ticketIndex, struct AccountTicketingData* data, int maxElements)
{
	int i, index = 0;
	for (i = 0; i < maxElements; i++)
	{
		if (data->tickets[ticketIndex].accNum == data->accounts[i].accountNumber)
		{
			index = i;
			break;
		}
	}
	return index;
}

int checkMessageBox(int ticketIndex, struct AccountTicketingData* data, int maxElements)
{
	int flag = 0;

	if (data->tickets[ticketIndex].statusIndicator == 0)
	{
		flag = -1;
		printf("\nERROR: Ticket is closed - new messages are not permitted.\n\n");
		pauseExecution();
	}
	else if (data->tickets[ticketIndex].count == maxElements)
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

int checkTicketBox(int accountIndex, struct AccountTicketingData* data, int maxElements)
{
	int i, flag = 0;
	if (data->accounts[accountIndex].accountType == 'A')
	{
		printf("\nERROR: Agent accounts can't have tickets!\n\n");
		pauseExecution();
	}
	else
	{
		for (i = 0; i < maxElements; i++)
		{
			if (data->tickets[i].uniqNum == '\0')
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

void manageTicket(struct AccountTicketingData* data, const struct Account* login)
{
	int ticketIndex, accountIndex, messageIndex = 0, selection, flag = 0;
	char intention;
	ticketIndex = findTicketIndexThroughTicketNum(data, TICKET_SIZE);
	accountIndex = findAccountIndexThroughTicketIndex(ticketIndex, data, ACCOUNT_SIZE);

	if (ticketIndex == -1)
	{
		printf("ERROR: Invalid ticket number.\n");
	}
	else
	{
		do
		{
			printf("\n----------------------------------------\n");
			printf("Ticket %06d - Update Options\n", data->tickets[ticketIndex].uniqNum);
			printf("----------------------------------------\n");
			printf("Status  : %s\n", data->tickets[ticketIndex].statusIndicator == 1 ? "ACTIVE" : "CLOSED");
			printf("Subject : %s\n", data->tickets[ticketIndex].subjectLine);
			printf("Acct#   : %d\n", data->tickets[ticketIndex].accNum);
			printf("Customer: %s\n", data->accounts[accountIndex].person.name);
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
				printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
				messageIndex = data->tickets[ticketIndex].count;
				flag = checkMessageBox(ticketIndex, data, MAX_MESSAGE_STORE);
				if (flag != -1)
				{
					getCString(data->tickets[ticketIndex].message[messageIndex].messageDetails, 1, MAX_MESSAGE_LENGTH);
					strcpy(data->tickets[ticketIndex].message[messageIndex].name, data->accounts[accountIndex].person.name);
					data->tickets[ticketIndex].message[messageIndex].accountType = 'C';
					data->tickets[ticketIndex].count++;
				}
			}
			else if (selection == 2)
			{
				printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSAGE_LENGTH);
				messageIndex = data->tickets[ticketIndex].count;
				flag = checkMessageBox(ticketIndex, data, MAX_MESSAGE_STORE);
				if (flag != -1)
				{
					getCString(data->tickets[ticketIndex].message[messageIndex].messageDetails, 1, MAX_MESSAGE_LENGTH);
					strcpy(data->tickets[ticketIndex].message[messageIndex].name, login->person.name);
					data->tickets[ticketIndex].message[messageIndex].accountType = 'A';
					data->tickets[ticketIndex].count++;
				}
			}
			else if (selection == 3)
			{
				if (data->tickets[ticketIndex].statusIndicator == 0)
				{
					printf("\nERROR: Ticket is already closed!\n");
				}
				else
				{
					printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
					intention = getCharOption("yYnN");
					if (intention == 'y' || intention == 'Y')
					{
						data->tickets[ticketIndex].statusIndicator = 0;
						printf("\n*** Ticket closed! ***\n");
					}
				}
			}
			else if (selection == 4)
			{
				if (data->tickets[ticketIndex].statusIndicator == 1)
				{
					printf("\nERROR: Ticket is already active!\n");
				}
				else
				{
					printf("\nAre you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
					intention = getCharOption("yYnN");
					if (intention == 'y' || intention == 'Y')
					{
						data->tickets[ticketIndex].statusIndicator = 1;
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

