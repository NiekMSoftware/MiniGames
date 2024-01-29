#include <stdio.h>
#include "TicTacToe/TicTacToe.h"
#include "Hangman/Hangman.h"

int GetInput(string prompt);
void ProcessInput(int input);

void main()
{
	printf("=== MINIGAMES ===");

	while(true)
	{
		cout << "\n\n";
		printf("Choose what you want to play:\n");
		printf("1) Tic Tac Toe\n");
		printf("2) Hangman\n");
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

		case -1:
			delete hangMan;
			delete tic_tac_toe;
			exit(0);

		default:
			cout << "\n";
			std::cout << "Out of range!\n\n";
			break;
	}
}