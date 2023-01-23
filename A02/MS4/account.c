// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS
#define ACCOUNT_SIZE 5

#include <stdio.h>
#include <ctype.h>
#include "account.h"

void getAccount(struct Account* accPoint)
{
	int i = 0, idx = 0, bigNum = 0;
	for (i = 0; i < ACCOUNT_SIZE; i++)
	{
		if (accPoint[i].accountNumber == '\0')
		{
			idx = i;
			break;
		}
	}

	for (i = 0; i < ACCOUNT_SIZE; i++)
	{
		if (accPoint[i].accountNumber > 0)
		{
			if (bigNum < accPoint[i].accountNumber)
			{
				bigNum = accPoint[i].accountNumber;
			}
		}
	}
	accPoint[idx].accountNumber = bigNum + 1;
	printf("\nNew Account Data (Account#:%d)\n", accPoint[idx].accountNumber);
	printf("----------------------------------------");
	printf("\nEnter the account type (A=Agent | C=Customer): ");
	accPoint[idx].accountType = getCharOption("AC");
	printf("\n");
	getPerson(&accPoint[idx].person);
	if (accPoint[idx].accountType == 'A')
	{
		getUserLogin(&accPoint[idx].login);
	}
	else
	{
		accPoint[idx].login.ID[0] = '\0';
		accPoint[idx].login.password[0] = '\0';
	}
}

void getPerson(struct Person* perPoint)
{
	int i;
	printf("Person Data Input\n----------------------------------------\n");
	printf("Enter the person's full name (%d chars max): ", MAX_LENGTH);
	getCString(perPoint->name, 1, MAX_LENGTH);
	printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
	perPoint->birthYear = getIntFromRange(currentYear() - MAX_AGE, currentYear() - MIN_AGE);
	printf("Enter the household Income: $");
	perPoint->income = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", MAX_LENGTH);
	getCString(perPoint->country, 1, MAX_LENGTH);
	for (i = 0; i < MAX_LENGTH; i++)
	{
		perPoint->country[i] = toupper(perPoint->country[i]);
	}
	printf("\n");
}

void getUserLogin(struct UserLogin* logPoint)
{
	int i, flag = 1;
	printf("User Login Data Input\n----------------------------------------\n");
	do
	{
		printf("Enter user login (%d chars max): ", MAX_ID_LENGTH);
		getCString(logPoint->ID, 1, MAX_ID_LENGTH);
		for (i = 0; i < MAX_ID_LENGTH; i++)
		{
			if (logPoint->ID[i] == ' ')
			{
				flag = 1;
				printf("ERROR:  The user login must NOT contain whitespace characters.\n");
				break;
			}
			else if (logPoint->ID[i] != ' ' && i + 1 == MAX_ID_LENGTH)
			{
				flag = 0;
			}
		}
	} while (flag);
	passwordForm(logPoint);
	printf("\n");
}
void updateAccount(struct Account* accPoint)
{
	int select = 0;
	char type;
	do
	{
		printf("Update Account: %05d (%s)\n", accPoint->accountNumber, accPoint->person.name);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", accPoint->accountType);
		printf("2) Person\n");
		printf("3) Login\n");
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 3);
		if (select == 1)
		{
			printf("\nEnter the account type (A=Agent | C=Customer): ");
			type = getCharOption("AC");
			if (type == 'A')
			{
				printf("\nAgent type accounts require a user login.  Please enter this information now:\n\n");
				getUserLogin(&accPoint->login);
				accPoint->accountType = 'A';
			}
			else if (type == 'C')
			{
				printf("\n");
				accPoint->accountType = 'C';
				accPoint->login.ID[0] = '\0';
				accPoint->login.password[0] = '\0';
			}
		}
		else if (select == 2)
		{
			updatePerson(&accPoint->person);
		}
		else if (select == 3)
		{
			if (accPoint->accountType == 'A')
			{
				updateUserLogin(&accPoint->login);
			}
			else
			{
				printf("\nERROR:  Customer account types don't have user logins!\n\n");
			}
		}
		else
		{
			printf("\n");
		}
	} while (select != 0);
}

void updatePerson(struct Person* perPoint)
{
	int i, select = 0;
	do
	{
		printf("\nPerson Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Full name (current value: %s)\n", perPoint->name);
		printf("2) Household Income (current value: $%.2lf)\n", perPoint->income);
		printf("3) Country (current value: %s)\n", perPoint->country);
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 3);
		if (select == 1)
		{
			printf("\nEnter the person's full name (30 chars max): ");
			getCString(perPoint->name, 1, MAX_LENGTH);
		}
		else if (select == 2)
		{
			printf("\nEnter the household Income: $");
			perPoint->income = getPositiveDouble();
		}
		else if (select == 3)
		{
			printf("\nEnter the country (30 chars max.): ");
			getCString(perPoint->country, 1, MAX_LENGTH);
			for (i = 0; i < MAX_LENGTH; i++)
			{
				perPoint->country[i] = toupper(perPoint->country[i]);
			}
		}
		else
		{
			printf("\n");
		}
	} while (select != 0);
}

void updateUserLogin(struct UserLogin* logPoint)
{
	int select = 0;
	do
	{
		printf("\nUser Login: %s - Update Options\n", logPoint->ID);
		printf("----------------------------------------\n");
		printf("1) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 1);
		if (select == 1)
		{
			printf("\n");
			passwordForm(logPoint);
		}
		else
		{
			printf("\n");
		}
	} while (select != 0);
}

void passwordForm(struct UserLogin* logPoint)
{
	int i, j, flag = 1;
	char* special = "!@#$%^&*";
	char* digits = "0123456789";
	char* upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* lower = "abcdefghijklmnopqrstuvwxyz";
	do
	{
		int Dcount = 0, Scount = 0, Ucount = 0, Lcount = 0;
		printf("Enter the password (must be %d chars in length): ", PW_LENGTH);
		getCString(logPoint->password, PW_LENGTH, PW_LENGTH);
		for (i = 0; i < PW_LENGTH; i++)
		{
			for (j = 0; *(special + j) != '\0'; j++)
			{
				if (logPoint->password[i] == *(special + j))
				{
					Scount++;
				}
			}
			for (j = 0; *(upper + j) != '\0'; j++)
			{
				if (logPoint->password[i] == *(upper + j))
				{
					Ucount++;
				}
				else if (logPoint->password[i] == *(lower + j))
				{
					Lcount++;
				}
			}
			for (j = 0; *(digits + j) != '\0'; j++)
			{
				if (logPoint->password[i] == *(digits + j))
				{
					Dcount++;
				}
			}
		}
		if (Scount == 2 && Ucount == 2 && Lcount == 2 && Dcount == 2)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
			printf("SECURITY: Password must contain 2 of each:\n");
			printf("          Digit: 0-9\n");
			printf("          UPPERCASE character\n");
			printf("          lowercase character\n");
			printf("          symbol character: !@#$%%^&*\n");
		}
	} while (flag);
}