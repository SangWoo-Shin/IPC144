/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Sang Woo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Maximum_Path_Length 70
#define Minimum_Path_Length 10
#define Max_Life 10
#define Min_Life 1
#define Multiple 5

struct PlayerInfo
{
	char Symbol;
	int Lives;
	int Count_Treasures;
	int History[Maximum_Path_Length];
};
struct GameInfo
{
	int Path_Length;
	int Limit_Moves;
	int Bombs[Maximum_Path_Length];
	int Treasures[Maximum_Path_Length];
};

int main(void)
{
	struct PlayerInfo Player;
	struct GameInfo Game;
	int i ,j , flag = 1, major = 0, minor = 1, nextmove = 0;
	char undiscovered = '-', bombs = '!', treasures = '$', both = '&', neither = '.';
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");

	printf("\nPLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &Player.Symbol);
	do
	{
		flag = 0;
		printf("Set the number of lives: ");
		scanf("%d", &Player.Lives);
		if (Player.Lives < Min_Life || Player.Lives > Max_Life)
		{
			printf("     Must be between 1 and 10!\n");
			flag = 1;
		}
	} while (flag);
	printf("Player configuration set-up is complete\n");

	printf("\nGAME Configuration\n");
	printf("------------------\n");
	do
	{
		flag = 0;
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &Game.Path_Length);
		if (Game.Path_Length < Minimum_Path_Length || Game.Path_Length > Maximum_Path_Length || (Game.Path_Length % Multiple) != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
			flag = 1;
		}
	} while (flag);

	do
	{
		flag = 0;
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &Game.Limit_Moves);
		if (Game.Limit_Moves < Player.Lives || Game.Limit_Moves > 3 * Game.Path_Length / 4)
		{
			printf("    Value must be between %d and %d\n", Player.Lives, 3 * Game.Path_Length / 4);
			flag = 1;
		}
	} while (flag);

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path_Length);
	for (i = 0; i < (Game.Path_Length / Multiple); i++)
	{
		printf("   Positions [%2d-%2d]: ", (Multiple * i) + 1, Multiple * (i + 1));
		for (j = Multiple * i; j < Multiple * (i + 1); j++)
		{
			scanf("%d", &Game.Bombs[j]);
		}
	}
	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path_Length);
	for (i = 0; i < (Game.Path_Length / Multiple); i++)
	{
		printf("   Positions [%2d-%2d]: ", (Multiple * i) + 1, Multiple * (i + 1));
		for (j = Multiple * i; j < Multiple * (i + 1); j++)
		{
			scanf("%d", &Game.Treasures[j]);
		}
	}
	printf("TREASURE placement set\n");

	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings");
	printf("\n------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", Player.Symbol);
	printf("   Lives      : %d\n", Player.Lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", Game.Path_Length);
	printf("   Bombs      : ");
	for (i = 0; i < Game.Path_Length; i++)
	{
		printf("%d", Game.Bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < Game.Path_Length; i++)
	{
		printf("%d", Game.Treasures[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================");
	for (i = 0; i < Maximum_Path_Length; i++)
	{
		Player.History[i] = 0;
	}
	Player.Count_Treasures = 0;
	while (1)
	{
		for (i = 0; i < Game.Path_Length; i++)
		{
			if (Player.History[i] == 1 && i == (nextmove - 1))
			{
				printf("  ");
				printf("%c", Player.Symbol);
			}
			else if (nextmove == 0)
			{
				printf("\n");
				i = Game.Path_Length;
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < Game.Path_Length; i++)
		{
			if (Player.History[i] == 0)
			{
				printf("%c", undiscovered);
			}
			else if (Game.Bombs[i] == 1 && Game.Treasures[i] == 1)
			{
				printf("%c", both);
			}
			else if (Game.Bombs[i] == 1)
			{
				printf("%c", bombs);
			}
			else if (Game.Treasures[i] == 1)
			{
				printf("%c", treasures);
			}
			else
			{
				printf("%c", neither);
			}
		}
		printf("\n  ");

		for (i = 0; i < Game.Path_Length; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				++major;
				printf("%d", major);
			}
			else
			{
				printf("|");
			}
		}
		major = 0;
		printf("\n  ");
		for (i = 0; i < Game.Path_Length; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				printf("0");
				minor = 1;
			}
			else
			{
				printf("%d", minor++);
			}
		}
		printf("\n");

		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player.Lives, Player.Count_Treasures, Game.Limit_Moves);
		printf("+---------------------------------------------------+\n");
		if (Player.Lives == 0 || Game.Limit_Moves == 0)
		{
			break;
		}
		do
		{
			flag = 0;
			printf("Next Move [1-%2d]: ", Game.Path_Length);
			scanf("%d", &nextmove);
			if (nextmove > Game.Path_Length || nextmove < 1)
			{
				printf("  Out of Range!!!\n");
				flag = 1;
			}
		} while (flag);
		if (Player.History[nextmove - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n\n");
		}
		else
		{
			Player.History[nextmove - 1] = 1;
			Game.Limit_Moves--;
			if (Game.Bombs[nextmove - 1] == 1 && Game.Treasures[nextmove - 1] == 1)
			{
				Player.Lives--;
				Player.Count_Treasures++;
				printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", both, both);
				printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]\n\n", both, both);
				if (Player.Lives == 0)
				{
					printf("No more LIVES remaining!\n\n");
				}
				else if (Game.Limit_Moves == 0)
				{
					printf("No more MOVES remaining!\n\n");
				}
			}
			else if (Game.Bombs[nextmove - 1] == 1)
			{
				Player.Lives--;
				printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n\n", bombs, bombs);
				if (Player.Lives == 0)
				{
					printf("No more LIVES remaining!\n\n");
				}
				else if (Game.Limit_Moves == 0)
				{
					printf("No more MOVES remaining!\n\n");
				}
			}
			else if (Game.Treasures[nextmove - 1] == 1)
			{
				Player.Count_Treasures++;
				printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n\n", treasures, treasures);
				if (Game.Limit_Moves == 0)
				{
					printf("No more MOVES remaining!\n");
				}
			}
			else
			{
				printf("\n===============> [%c] ...Nothing found here... [%c]\n\n", neither, neither);
			}
		}
	}
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");
	printf("\nYou should play again and try to beat your score!\n");
	return 0;
}