// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
//  Student Name  : SangWoo Shin
//  Student ID    : 119294213
//  Student Email : sshin36@myseneca.ca
//  Course Section:  NFF
// #############################################################################################

#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"

void getAccount(struct Account* accPoint)
{
	printf("\nAccount Data: New Record\n----------------------------------------\n");
	printf("Enter the account number: ");
	accPoint->accountNumber = getInteger();
	printf("\nEnter the account type (A=Agent | C=Customer): ");
	accPoint->accountType = getCharOption("AC");
	printf("\n");
	getPerson(&accPoint->person);
	if (accPoint->accountType == 'A')
	{
		getUserLogin(&accPoint->login);
	}
	else
	{
		accPoint->login.ID[0] = '\0';
		accPoint->login.password[0] = '\0';
	}
}

void getPerson(struct Person* perPoint)
{
	printf("Person Data Input\n----------------------------------------\n");
	printf("Enter the person's full name (%d chars max): ", MAX_LENGTH);
	getCString(perPoint->name, 1, MAX_LENGTH);
	printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
	perPoint->birthYear = getIntFromRange(currentYear() - MAX_AGE, currentYear() - MIN_AGE);
	printf("Enter the household Income: $");
	perPoint->income = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", MAX_LENGTH);
	getCString(perPoint->country, 1, MAX_LENGTH);
	printf("\n");
}

void getUserLogin(struct UserLogin* logPoint)
{
	printf("User Login Data Input\n----------------------------------------\n");
	printf("Enter user login (%d chars max): ", MAX_ID_LENGTH);
	getCString(logPoint->ID, 1, MAX_ID_LENGTH);
	printf("Enter the password (must be %d chars in length): ", PW_LENGTH);
	getCString(logPoint->password, PW_LENGTH, PW_LENGTH);
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
	int select = 0;
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
			printf("\nEnter the password (must be 8 chars in length): ");
			getCString(logPoint->password, PW_LENGTH, PW_LENGTH);
		}
		else
		{
			printf("\n");
		}
	} while (select != 0);
}
