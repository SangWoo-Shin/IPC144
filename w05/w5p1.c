/*
	==================================================
	Workshop #5 (Part-1):
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
	int i = 0, flag = 1, j = 1;
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
		if (Player.Lives < 1 || Player.Lives > 10)
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
		if (Game.Path_Length < Minimum_Path_Length || Game.Path_Length > Maximum_Path_Length || (Game.Path_Length % 5) != 0)
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
	for (i = 0; i < (Game.Path_Length / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, 5 * (i + 1));
		for (j = 5 * i; j < 5 * (i + 1); j++)
		{
			scanf("%d", &Game.Bombs[j]);
		}
	}
	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.Path_Length);
	for (i = 0; i < (Game.Path_Length / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, 5 * (i + 1));
		for (j = 5 * i; j < 5 * (i + 1); j++)
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

	return 0;
}