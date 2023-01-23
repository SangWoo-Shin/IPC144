// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#define ACCOUNT_SIZE 50
#define INIT_DATA_SIZE 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"


void displayAccountDetailHeader(void)
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}

void displayAccountDetailRecord(const struct Account* accPoint)
{
	int i;
	printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s ", accPoint->accountNumber, accPoint->accountType == 'A' ? "AGENT" : "CUSTOMER", 
		accPoint->person.name, accPoint->person.birthYear,accPoint->person.income, accPoint->person.country, accPoint->login.ID);
	for (i = 0; accPoint->login.password[i] != '\0'; i++)
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
	printf("\n");
}

void applicationStartup(struct Account account[], int maxElements)
{
	int searchIndex = 0;
	do
	{
		searchIndex = menuLogin(account, maxElements);
		if (searchIndex != -1)
		{
			if (account[searchIndex].accountType == 'A')
			{
				printf("\n");
				menuAgent(account, maxElements, &account[searchIndex]);
			}
		}
	} while (searchIndex != -1);
}

int menuLogin(struct Account account[], int maxElements)
{
	int select=0, accNo=0, searchIndex, index =0;
	char intention;
	do
	{
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
			searchIndex = findAccountIndexByAcctNum(accNo, account, maxElements, 0);
			if (searchIndex >= 0 && account[searchIndex].accountType == 'A')
			{
				index = searchIndex;
				break;
			}
			else if (searchIndex >= 0 && account[searchIndex].accountType == 'C')
			{
				index - 1;
				printf("ERROR:  Login failed!\n\n");
				pauseExecution();
			}
			else if (searchIndex == -1)
			{
				index = -1;
				printf("ERROR:  Login failed!\n\n");
				pauseExecution();
			}
		}
		else if(select ==0)
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			intention = getCharOption("yYnN");
			if (intention == 'y' || intention == 'Y')
			{
				printf("\n==============================================\n");
				printf("Account Ticketing System - Terminated\n");
				printf("==============================================\n");
				index = -1;
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

void menuAgent(struct Account account[], int maxElements, const struct Account* login)
{
	int select = 0, i, searchIndex = 0;
	char intention;
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
		printf("0) Logout\n\n");
		printf("Selection: ");

		select = getIntFromRange(0, 4);
		if (select == 1)
		{
			for (i = 0; i < maxElements; i++)
			{
				if (account[i].accountNumber == 0)
				{
					getAccount(&account[i]);
					printf("*** New account added! ***\n\n");
					pauseExecution();
					i = maxElements;
				}
				else if (i + 1 == maxElements)
				{
					printf("ERROR: Account listing is FULL, call ITS Support!\n");
				}
			}
		}
		else if (select == 2)
		{
			searchIndex = findAccountIndexByAcctNum(0, account, maxElements, 1);
			if (searchIndex != -1)
			{
				updateAccount(&account[searchIndex]);
			}
			printf("\n");
		}
		else if (select == 3)
		{
			searchIndex = findAccountIndexByAcctNum(0, account, maxElements, 1);
			if (account[searchIndex].accountNumber == login->accountNumber)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
			}
			else
			{
				displayAccountDetailHeader();
				displayAccountDetailRecord(&account[searchIndex]);
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				intention = getCharOption("yYnN");
				if (intention == 'y' || intention == 'Y')
				{
					account[searchIndex].accountNumber = 0;
				}
				printf("\n*** Account Removed! ***\n\n");
				pauseExecution();
			}
		}
		else if (select == 4)
		{
			displayAllAccountDetailRecords(account, maxElements);
			printf("\n");
			pauseExecution();
		}
		else if (select == 0)
		{
			printf("\n### LOGGED OUT ###\n\n");
			break;

		}
	} while (select != 0);

}

int findAccountIndexByAcctNum(int accNo, const struct Account account[], int maxElements, int flag)
{
	int searchIndex = -1, i;
	if (flag == 0)
	{
		printf("\nEnter your account#: ");
		accNo = getPositiveInteger();
		for (i = 0; i < maxElements; i++)
		{
			if (account[i].accountNumber == accNo)
			{
				searchIndex = i;
				break;
			}
		}
	}
	else if(flag == 1)
	{
		printf("\nEnter the account#: ");
		accNo = getPositiveInteger();
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
	printf("<< ENTER key to Continue... >> ");
	clearStandardInputBuffer();
	putchar('\n');
}