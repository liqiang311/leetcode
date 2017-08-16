/* 
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		BackTrack(board,0,0);
	}
	bool BackTrack(vector<vector<char>>& board, int startx, int starty)
	{
		for (int y=starty; y<9; y++)
		{
			for (int x=0; x<9; x++)
			{
				if (y == starty && x < startx) continue;
				//从这个位置开始寻找一个空闲的
				if (board[y][x] == '.')
				{
					for (char c='1'; c<='9'; c++)
					{
						board[y][x] = c;
						if (false == isValid(board, x, y, c)) continue;
						if (x == 8)
							if (false == BackTrack(board,0,y+1)) continue;
						else
							if (false == BackTrack(board,x+1,y)) continue;
					}
				}
			}
		}
	}
	//填充这个位置是否合理, x为第几列, y为第几行
	bool isValid(vector<vector<char>>& board, int x, int y, char value)
	{
		//这行列有无重复
		for (int i=0; i<9; i++)
		{
			if (i != y)
			{
				if (value == board[i][x]) return false;
			}
			if (i != x)
			{
				if (value == board[y][i]) return false;
			}
		}
		//所在块是否有重复
		int startx = x % 3;
		int starty = y % 3;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (startx + j == x && starty + i == y) continue;
				if (value == board[starty+i][startx+j]) return false;
			}
		}
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;
	vector<vector<char>> board;
	char b1[10] = "..9748...";
	board.push_back(vector<char>(b1,b1+9));
	char b2[10] = "7........";
	board.push_back(vector<char>(b2,b2+9));
	char b3[10] = ".2.1.9...";
	board.push_back(vector<char>(b3,b3+9));
	char b4[10] = "..7...24.";
	board.push_back(vector<char>(b4,b4+9));
	char b5[10] = ".64.1.59.";
	board.push_back(vector<char>(b5,b5+9));
	char b6[10] = ".98...3..";
	board.push_back(vector<char>(b6,b6+9));
	char b7[10] = "...8.3.2.";
	board.push_back(vector<char>(b7,b7+9));
	char b8[10] = "........6";
	board.push_back(vector<char>(b8,b8+9));
	char b9[10] = "...2759..";
	board.push_back(vector<char>(b9,b9+9));
	t1 = clock();

	t2 = clock();
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}