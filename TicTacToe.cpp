// Tic Tac Toe

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_board(vector<string> board)
{
	for (int i = 0; i < 9; i++) {
		cout << board[i];
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}

	}
}

string get_player_input()
{
	string player_input;
	cin.clear();
	cout << "Enter a command: ";
	cin.ignore(512, '\n');
	cin >> player_input;
	return player_input;
}

vector<string> check_for_move(string player_input, vector<string> board)
{
	for (int i = 0; i < 9; i++) {
		if (player_input == to_string(i) && board[i] != "X" && board[i] != "O") {
			board[stoi(player_input)] = "X";
		}
	}
	return board;
}

void print_instructions()
{
	cout << "Type a number to make a move." << endl;
	cout << "Type exit to exit the program." << endl;
}

string check_for_win(vector<string> board)
{
	string win;
	int winpositions[8][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 },
	{ 0,3,6 },{ 1,4,7 },{ 2,5,8 },
	{ 0,4,8 },{ 2,4,6 } };
	for (int i = 0; i < 8; i++) {
		if (board[winpositions[i][0]] == "X" && board[winpositions[i][1]] == "X" && board[winpositions[i][2]] == "X") {
			win = "Player";
		}
		if (board[winpositions[i][0]] == "O" && board[winpositions[i][1]] == "O" && board[winpositions[i][2]] == "O") {
			win = "Computer";
		}
	}
	return win;
}

void print_player_win_message()
{
	cout << "Congratulations you have won!" << endl;
}

void print_computer_win_message()
{
	cout << "You have lost! Try again!" << endl;
}

vector<string> computer_move(vector<string> board)
{
	srand((unsigned int)time(NULL)); //initialize the random seed
	vector<int> positions_available;
	for (int i = 0; i < 9; i++) {
		if (board[i] != "X" && board[i] != "O") {
			positions_available.push_back(i);
		}
	}
	int rand_index = rand() % positions_available.size();
	board[positions_available[rand_index]] = "O";
	positions_available.clear();
	return board;
}

int main()
{
	print_instructions();
	vector<string> board(9);
	for (int i = 0; i < 9; i++) { board[i] = to_string(i); }
	print_board(board);
	bool running = true;
	string win;
	while (running) {
		string player_input = get_player_input();
		if (player_input == "exit") {
			running = false;
		}
		board = check_for_move(player_input, board);
		win = check_for_win(board);
		if (win == "Player") {
			print_board(board);
			print_player_win_message();
			break;
		}
		print_board(board);
		board = computer_move(board);
		win = check_for_win(board);
		if (win == "Computer") {
			print_board(board);
			print_computer_win_message();
			break;
		}
		cout << "Computer: I have made a move." << endl;
		print_board(board);
		string win = check_for_win(board);
	}
	system("pause");

}
