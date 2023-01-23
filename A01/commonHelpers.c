//==================================
//  Assignments #1 Milestone #1
//  Name: Sang Woo Shin
//  ID: 119294213
//  Email: sshin36@myseneca.ca
//  Section: NFF
//===================================

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 30

#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"

const char name[MAX_LENGTH];
char cString[MAX_LENGTH];

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; //On purpose: do nothing
	}
}

int getInteger(void)
{
	char newLine = 'x';
	int intValue;

	while (1)
	{
		scanf("%d%c", &intValue, &newLine);
		if (intValue % 1 == 0 && newLine == '\n')
		{
			return intValue;
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
		}

		printf("ERROR: Value must be an integer: ");
	}
}
int getPositiveInteger(void)
{
	char newLine = 'x';
	int intValue;

	while (1)
	{
		scanf("%d%c", &intValue, &newLine);
		if (intValue % 1 == 0 && newLine == '\n')
		{
			if (intValue > 0)
			{
				return intValue;
			}
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
		}
		printf("ERROR: Value must be a positive integer greater than zero: ");
	}
}

double getDouble(void)
{
	char newLine = 'x';
	double doValue;

	while (1)
	{
		scanf("%lf%c", &doValue, &newLine);
		if (doValue == 0 && newLine == '\n')
		{
			printf("ERROR: Value must be a double floating-point number: ");
		}
		if ((int)(doValue * 100) % 100 != 0 && newLine == '\n')
		{
			return doValue;
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
		}
		printf("ERROR: Value must be a double floating-point number: ");
	}
}

double getPositiveDouble(void)
{
	char newLine = 'x';
	double doValue;

	while (1)
	{
		scanf("%lf%c", &doValue, &newLine);
		if (doValue == 0 && newLine == '\n')
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else if ((int)(doValue * 100) % 100 != 0 && newLine == '\n')
		{
			if (doValue > 0)
			{
				return doValue;
			}
			else
			{
				printf("ERROR: Value must be a positive double floating-point number: ");
			}
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	}
}

int getIntFromRange(int lowerBound, int upperBound)
{
	char newLine = 'x';
	int intValue;

	while (1)
	{
		scanf("%d%c", &intValue, &newLine);
		if (intValue % 1 == 0 && newLine == '\n')
		{
			if (intValue >= lowerBound && intValue <= upperBound)
			{
				return intValue;
			}
			else
			{
				printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
			}
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}
}

char getCharOption(const char name[])
{
	char newLine = 'x';
	char charValue;
	int i = 0;

	while (1)
	{
		scanf("%c%c", &charValue, &newLine);
		if (newLine == '\n')
		{
			for (i = 0; name[i] != '\0'; i++)
			{
				if (name[i] == charValue)
				{
					return charValue;
				}
			}
			printf("ERROR: Character must be one of [%s]: ", name);
		}
		else if (newLine != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Character must be one of [%s]: ", name);
		}
	}
}

void getCString(char* cString, int lowerBound, int upperBound)
{
	while (1)
	{
		char newLine = 'x';
		char userString[MAX_LENGTH] = { 0 };
		int length = 0, i =0;
		scanf(" %30[^\n]%c", userString, &newLine);
		if (newLine == '\n')
		{
			for (i = 0; userString[i] != '\0'; i++)
			{
				if (userString[i + 1] == '\0')
				{
					length = i + 1;
				}
			}	
			if (lowerBound == upperBound)
			{
				if (length == upperBound)
				{
					for (i = 0; i < length; i++)
					{
						cString[i] = userString[i];
					}
					cString[length] = '\0';
					break;
				}
				else
				{
					printf("ERROR: String length must be exactly %d chars: ", upperBound);
				}
			}
			else if (length >= lowerBound && length <= upperBound)
			{
				if ((length == upperBound) && (upperBound != lowerBound))
				{
					for (i = 0; i < length; i++)
					{
						cString[i] = userString[i];
					}
					cString[length] = '\0';
					break;
				}
				else
				{
					for (i = 0; i < length; i++)
					{
						cString[i] = userString[i];
					}
					cString[length] = '\0';	
					break;
				}
			}
			else if (length > upperBound)
			{
				printf("ERROR: String length must be no more than %d chars: ", upperBound); 
			}
			else
			{
				printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
			}
		}
	}
}
