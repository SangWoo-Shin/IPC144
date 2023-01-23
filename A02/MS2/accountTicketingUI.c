// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#define ACCOUNT_SIZE 5
#define TICKET_SIZE 20
#define INIT_DATA_SIZE 5
#define ATTEMPTS 3
#define USER_INPUT 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "accountTicketingUI.h"


void displayAccountDetailHeader(void)
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}

void displayAccountDetailRecord(const struct Account* accPoint)
{
	int i;

	printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s ", accPoint->accountNumber, accPoint->accountType == 'A' ? "AGENT" : "CUSTOMER", accPoint->person.name, accPoint->person.birthYear,
		accPoint->person.income, accPoint->person.country, accPoint->login.ID);
	for (i = 0; i < PW_LENGTH; i++)
	{
		if (accPoint->accountType == 'A')
		{
			if (i % 2 == 0)
			{
				printf("%c", accPoint->login.password[i]);
			}
			else
			{
				printf("*");
			}
		}
		else if (accPoint->accountType == 'C')
		{
			printf(" ");
		}
	}
	printf("\n");
}

void applicationStartup(struct  AccountTicketingData* data)
{
	int searchIndex = 0;
	do
	{
		searchIndex = menuLogin(data->accounts, data->ACCOUNT_MAX_SIZE);
		if (searchIndex != -1)
		{
			if (data->accounts[searchIndex].accountType == 'A')
			{
				menuAgent(data, &data->accounts[searchIndex]);
			}
		}
	} while (searchIndex != -1);
}

int menuLogin(struct Account account[], int maxElements)
{
	int select = 0, accNo = 0, searchIndex, index = -1;
	char intention;
	do
	{
		char userID[USER_INPUT] = { 0 };
		char userPW[USER_INPUT] = { 0 };
		int attempts = ATTEMPTS;
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n\n");
		printf("Selection: ");

		select = getIntFromRange(0, 1);
		if (select == 1)
		{
			do
			{
				searchIndex = findAccountIndexByAcctNum(accNo, account, maxElements, 1);
				printf("User Login        : ");
				scanf("%s", userID);
				printf("Password          : ");
				scanf("%s", userPW);
				if (searchIndex == -1)
				{
					--attempts;
					printf("INVALID user login/password combination! [attempts remaining:%d]\n", attempts);
				}
				else if (searchIndex >= 0 && account[searchIndex].accountType == 'C')
				{
					--attempts;
					printf("INVALID user login/password combination! [attempts remaining:%d]\n", attempts);
				}
				else if (searchIndex >= 0 && account[searchIndex].accountType == 'A')
				{
					if (strcmp(userID, account[searchIndex].login.ID) == 0)
					{
						if (strcmp(userPW, account[searchIndex].login.password) == 0)
						{
							index = searchIndex;
							select = 0;
							break;
						}
						else
						{
							--attempts;
							printf("INVALID user login/password combination! [attempts remaining:%d]\n", attempts);
						}
					}
					else
					{
						--attempts;
						printf("INVALID user login/password combination! [attempts remaining:%d]\n", attempts);
					}
				}
				if (attempts == 0)
				{
					printf("\nERROR:  Access Denied.\n\n");
					clearStandardInputBuffer();
					pauseExecution();
				}
			} while (attempts != 0);
		}
		else if (select == 0)
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			intention = getCharOption("yYnN");
			if (intention == 'y' || intention == 'Y')
			{
				printf("\n==============================================\n");
				printf("Account Ticketing System - Terminated\n");
				printf("==============================================\n");
			}
			else
			{
				printf("\n");
				select = 1;
			}
		}
	} while (select != 0);
	printf("\n");
	return index;
}

void menuAgent(struct AccountTicketingData* data, const struct Account* login)
{
	int select = 0, i, searchIndex = 0, ticketIndex =0, accountIndex =0, flag = 0;
	char intention, loginName[MAX_LENGTH] = { 0 };
	do
	{
		printf("AGENT: %s (%d)\n", login->person.name, login->accountNumber);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("5) List new tickets\n");
		printf("6) List active tickets\n");
		printf("7) List closed tickets\n");
		printf("8) Add a new ticket\n");
		printf("9) Manage a ticket\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");

		select = getIntFromRange(0, 9);
		if (select == 1)
		{
			for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
			{
				if (data->accounts[i].accountNumber == '\0')
				{
					getAccount(data->accounts);
					printf("*** New account added! ***\n\n");
					pauseExecution();
					break;
				}
				else if (i + 1 == data->ACCOUNT_MAX_SIZE)
				{
					printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
					pauseExecution();
				}
			}
		}
		else if (select == 2)
		{
			searchIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
			if (searchIndex != -1)
			{
				printf("\n");
				updateAccount(&data->accounts[searchIndex]);
			}
		}
		else if (select == 3)
		{
			int loginAccNum;
			loginAccNum = login->accountNumber;
			removeAccount(data, ACCOUNT_SIZE, loginAccNum);
			
		}
		else if (select == 4)
		{
			displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
			printf("\n");
			pauseExecution();
		}
		else if (select == 5)
		{
			printf("\n");
			displaySpecificTicketDetailRecords(data, TICKET_SIZE, 1, 0);
		}
		else if (select == 6)
		{
			printf("\n");
			displaySpecificTicketDetailRecords(data, TICKET_SIZE, 1, 1);
		}
		else if (select == 7)
		{
			printf("\n");
			displaySpecificTicketDetailRecords(data, TICKET_SIZE, 0, 1);
		}
		else if (select == 8)
		{
			accountIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
			flag = checkTicketBox(accountIndex, data->accounts[accountIndex].accountType, data->tickets, TICKET_SIZE);
			if (flag == 1)
			{
				printf("\n");
				displayAccountDetailHeader();
				displayAccountDetailRecord(&data->accounts[accountIndex]);
				printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
				intention = getCharOption("yYnN");
				if (intention == 'y' || intention == 'Y')
				{
					addNewTicket(data->tickets, data->accounts[accountIndex].accountNumber, data->accounts[accountIndex].person.name);
				}	
			}
		}
		else if (select == 9)
		{
			ticketIndex = findTicketIndexThroughTicketNum(data->tickets, TICKET_SIZE);
			accountIndex = findAccountIndexThroughTicketIndex(ticketIndex, data, ACCOUNT_SIZE);
			strcpy(loginName, login->person.name);
			manageTicket(ticketIndex, accountIndex, data->tickets, data->accounts[accountIndex].person.name, loginName);
		}
		else if (select == 0)
		{
			printf("\n### LOGGED OUT ###\n\n");
		}
	} while (select != 0);

}

int findAccountIndexByAcctNum(int accNo, const struct Account account[], int maxElements, int flag)
{
	int searchIndex = -1, i;
	if (flag == 0)
	{
		printf("\nEnter your account#: ");
		accNo = getInteger();
		for (i = 0; i < maxElements; i++)
		{
			if (account[i].accountNumber == accNo)
			{
				searchIndex = i;
				break;
			}
		}
	}
	else if (flag == 1)
	{
		printf("\nEnter the account#: ");
		accNo = getInteger();
		for (i = 0; i < maxElements; i++)
		{
			if (account[i].accountNumber == accNo)
			{
				searchIndex = i;
				break;
			}
		}
	}
	return searchIndex;
}

void displayAllAccountDetailRecords(const struct Account account[], int maxElements)
{
	int i = 0;
	printf("\n");
	displayAccountDetailHeader();
	for (i = 0; i < maxElements; i++)
	{
		if (account[i].accountNumber > 0)
		{
			displayAccountDetailRecord(&account[i]);
		}
	}
}

void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}

int findAccountIndexThroughTicketIndex(int ticketIndex, struct AccountTicketingData* data, int maxElements)
{
	int i, index = -1;
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


void  displaySpecificTicketDetailRecords(struct AccountTicketingData* data, int maxElements, int Indicator, int flag)
{
	int i, choice = 0, accIdx;
	char name[MAX_LENGTH] = { 0 };
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
					strcpy(name, data->accounts[accIdx].person.name);
					displayTicketDetailRecord(&data->tickets[i], name);
				}
			}
			printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
			choice = confirmMessage(data->tickets, maxElements, Indicator);
		}
		else if (flag == 1) // Active ticket or Closed ticket
		{
			for (i = 0; i < maxElements; i++)
			{
				if (data->tickets[i].statusIndicator == Indicator && data->tickets[i].count > 0)
				{
					accIdx = findAccountIndexThroughTicketIndex(i, data, ACCOUNT_SIZE);
					strcpy(name, data->accounts[accIdx].person.name);
					displayTicketDetailRecord(&data->tickets[i], name);
				}
			}
			printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
			choice = confirmMessage(data->tickets, maxElements, Indicator);
		}
	} while (choice != 0);
}

void removeAccount(struct AccountTicketingData* data, int maxElements, int loginAccNum)
{
	int ticketCount = 0, accountIndex = 0, i =0;
	char intention;
	accountIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
	if (data->accounts[accountIndex].accountNumber == loginAccNum)
	{
		printf("\nERROR: You can't remove your own account!\n\n");
		pauseExecution();
	}
	else
	{
		printf("\n");
		displayAccountDetailHeader();
		displayAccountDetailRecord(&(data->accounts[accountIndex]));
		printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
		intention = getCharOption("yYnN");
		if (intention == 'y' || intention == 'Y')
		{
			for (i = 0; i < maxElements; i++)
			{
				if (data->accounts[accountIndex].accountNumber == data->tickets[i].accNum)
				{
					data->tickets[i].accNum = '\0';
					data->tickets[i].uniqNum = '\0';
					data->tickets[i].count = '\0';

					ticketCount++;
				}
			}
			data->accounts[accountIndex].accountNumber = '\0';
		}
		printf("\n*** Account Removed! (%d ticket(s) removed) ***\n\n", ticketCount);
		pauseExecution();
	}
}