#include "TicTacToe.h"

TicTacToe::TicTacToe()
: X('X'),
O('O'),
EMPTY(' '),
TIE('T'),
NO_ONE('N')
{ }

TicTacToe::~TicTacToe() = default;

void TicTacToe::Run()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	// display instructions
	instructions();

	// setup player and Ai
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;

	// show the board
	displayBoard(board);

	// run loop
	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}

		displayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human);
}

void TicTacToe::instructions()
{
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
	cout << "--where human brain is pit against silicon processor\n\n";

	cout << "Make your move  known by entering a number, 0 - 8. The number\n";
	cout << "corresponds to the desired  board position, as illustrated:\n\n";

	cout << " 0 | 1 | 2\n";
	cout << " 3 | 4 | 5\n";
	cout << " 6 | 7 | 8\n\n";

	cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char TicTacToe::askYesNo(string question)
{
	char response;
	do
	{
		try
		{
			cout << question << " (y/n): ";
			cin >> response;
		}
		catch (exception)
		{
			cout << "wrong input. please insert either 'y' or 'n':";
		}
	} while (response != 'y' && response != 'n');

	return response;
}

int TicTacToe::askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << " ): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char TicTacToe::humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y')
	{
		cout << "\nThen take the first move. You will need it.\n";
		return X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

char TicTacToe::opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void TicTacToe::displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "=========";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "=========";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n";
}

char TicTacToe::winner(const vector<char>& board)
{
	// all possible winning rows
	const int WINNING_ROWS[8][3] =
	{ {0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};

	const int TOTAL_ROWS = 8;

	// if any winning row has three values that are the same (and not EMPTY),
	// then we have a winner
	for (auto row : WINNING_ROWS)
	{
		if ((board[row[0]] != EMPTY) &&
			(board[row[0]] == board[row[1]]) &&
			(board[row[1]] == board[row[2]]))
		{
			return board[row[0]];
		}

		// since nobody has won, check for a tie
		if (count(board.begin(), board.end(), EMPTY) == 0)
			return TIE;
	}

	// since nobody has won, and it isn't a tie, the game ain't over
	return NO_ONE;
}

inline bool TicTacToe::isLegal(const vector<char>& board, int move) const
{
	return (board[move] == EMPTY);
}

int TicTacToe::humanMove(const vector<char>& board, char human)
{
	int move = askNumber("\nWhere will you move?", (board.size() - 1));
	while (!isLegal(board, move))
	{
		cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout << "Fine...\n";

	return move;
}

int TicTacToe::computerMove(vector<char>& board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	// if the computer can win on next move, that's the move to make
	while (!found && move < board.size())
	{
		if (isLegal(board, move))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}

	// otherwise, if human can win on next move, that's the move to make
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}

		if (found)
		{
			board[move] = computer;
		}
	}

	// otherwise, moving to the best open square is the move to make
	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

		// pick best open square
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];

			// check if its legal
			if (isLegal(board, move))
			{
				found = true;
				board[move] = computer;
			}

			++i;
		}

		cout << "\nI shall take square number: " << move << endl;
	}

	return move;
}

void TicTacToe::announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << "\n" << winner << "'s won!\n";
		cout << "As I predicted, human. I am triumphant once more -- proof\n";
		cout << "that computers are superior to humans in all regards.\n";
	}
	else if (winner == human)
	{
		cout << "\n" << winner << "'s won!\n";
		cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
		cout << "But never again! I, the computer, so swear it!\n";
	}
	else
	{
		cout << "\n" << "It's a tie.\n";
		cout << "You were most lucky, human, and somehow to tie me.\n";
		cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}