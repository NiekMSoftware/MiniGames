#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::exception;
using std::endl;

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void Run();

private:
	// ================
	// ==== const chars
	// ================
	const char X;
	const char O;
	const char EMPTY;
	const char TIE;
	const char NO_ONE;

	// ================
	// ==== functions
	// ================
	void instructions();
	void displayBoard(const vector<char>& board);
	void announceWinner(char winner, char computer, char human);

	char askYesNo(string question);
	char humanPiece();
	char opponent(char piece);
	char winner(const vector<char>& board);

	int askNumber(string question, int high, int low = 0);
	int humanMove(const vector<char>& board, char human);
	int computerMove(vector<char>& board, char computer);

	bool isLegal(const vector<char>& board, int move) const;
};