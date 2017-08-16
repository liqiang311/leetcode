/* 
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//比较18次
		for (int i=0; i<9; i++)
		{
			//9行
			if (! isValid(board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7],board[i][8]))
			{
				return false;
			}
			//9列
			if (! isValid(board[0][i],board[1][i],board[2][i],board[3][i],board[4][i],board[5][i],board[6][i],board[7][i],board[8][i]))
			{
				return false;
			}
		}
		//9个块
		for (int i=0; i<9; i+=3)
		{
			for (int j=0; j<9; j+=3)
			{
				if (! isValid(board[i][j],board[i][j+1],board[i][j+2],board[i+1][j],board[i+1][j+1],board[i+1][j+2],board[i+2][j],board[i+2][j+1],board[i+2][j+2]))
				{
					return false;
				}
			}
		}
		return true;
	}
	bool isValid(char c1,char c2,char c3,char c4,char c5,char c6,char c7,char c8,char c9)
	{
		char buf[256];
		memset(buf,0,256);
		buf[c1]++;
		buf[c2]++;
		buf[c3]++;
		buf[c4]++;
		buf[c5]++;
		buf[c6]++;
		buf[c7]++;
		buf[c8]++;
		buf[c9]++;
		if (buf['1'] > 1 || buf['2'] > 1 || buf['3'] > 1 || buf['4'] > 1 ||
			buf['5'] > 1 || buf['6'] > 1 || buf['7'] > 1 || buf['8'] > 1 || buf['9'] > 1)
			return false;
		else
			return true;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;

	t1 = clock();
	//if (s.isValid('.','4','3','4','5','6','7','8','9'))
	if (s.isValid('.','.','.','.','.','.','.','.','.'))
		cout<<"zhen"<<endl;
	else
		cout<<"jia"<<endl;
	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}