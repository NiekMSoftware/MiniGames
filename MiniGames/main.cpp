#include <stdio.h>
#include "TicTacToe/TicTacToe.h"
#include "Hangman/Hangman.h"
#include "BlackJack/lib/Game.h"

int GetInput(string prompt);
void ProcessInput(int input);
void PlayBlackJack();

void main()
{
	printf("=== MINIGAMES ===");

	while(true)
	{
		cout << "\n\n";
		printf("Choose what you want to play:\n");
		printf("1) Tic Tac Toe\n");
		printf("2) Hangman\n");
		printf("3) Blackjack\n");
		printf("-1) Exit\n\n");

		ProcessInput(GetInput("> "));
	}
}

int GetInput(std::string prompt)
{
	int input = -10;

	while (input == -10)
	{
		cin >> input;
	}

	return input;
}

void ProcessInput(int input)
{
	TicTacToe* tic_tac_toe = new TicTacToe();
	Hangman* hangMan = new Hangman();

	switch (input)
	{
		case 1:
			cout << "\n";
			delete hangMan;
			tic_tac_toe->Run();
			break;

		case 2:
			cout << "\n";
			delete tic_tac_toe;
			hangMan->Run();
			break;

		case 3:
			cout << "\n";
			delete tic_tac_toe;
			delete hangMan;
			PlayBlackJack();
			break;

		case -1:
			printf("\n\nThanks for playing, bye-bye!\n");
			getchar();
			delete hangMan;
			delete tic_tac_toe;
			exit(0);

		default:
			cout << "\n";
			std::cout << "Out of range!\n\n";
			break;
	}
}

void PlayBlackJack()
{
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numOfPlayers = 0;
	while (numOfPlayers < 1 || numOfPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		cin >> numOfPlayers;
	}

	vector<string> names;
	string name;
	for (int i = 0; i < numOfPlayers; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << "\n";

	// the game loop
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;

		if (again == 'y' || again == 'Y')
		{
			aGame.Reset();
		}
	}
}
