#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Hangman
{
public:
	Hangman();

	void Run();

private:
	const int MAX_WRONG;
	int wrong;

	vector<string> words;
	string used;
	char guess;

	void Initialize();
	void GetGuess();
	bool OutOfGuess();
};