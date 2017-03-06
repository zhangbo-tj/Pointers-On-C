#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

int board[8][8];

void print_board() {
	static int solutions_number;

	solutions_number++;
	cout <<endl<< "Solution " << solutions_number << endl<<endl;
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if (board[row][column]) {
				cout << "Q  ";
			}
			else {
				cout << "+  ";
			}
		}
		cout << endl;
	}
}

int conflicts(int row, int column) {
	for (int i = 1; i < 8; i++) {
		if (row - i >= 0 && board[row - i][column])
			return TRUE;
		if (column - i >= 0 && board[row][column - i])
			return TRUE;
		if (column + i < 8 && board[row][column + i])
			return TRUE;

		if (row - i >= 0 && column - i >= 0 && board[row - i][column - i])
			return TRUE;
		if (row - i >= 0 && column + i < 8 && board[row - i][column + i])
			return TRUE;
	}
	return FALSE;
}


void place_queen(int row) {
	for (int column = 0; column < 8; column++) {
		board[row][column] = TRUE;
		if (row == 0 || !conflicts(row,column)) {
			if (row < 7) {
				place_queen(row + 1);
			}
			else {
				print_board();
			}
		}
		board[row][column] = FALSE;
	}
}

void main() {
	place_queen(0);
	system("pause");
	return;
}
