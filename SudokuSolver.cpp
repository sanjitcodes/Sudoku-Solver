/*Sudoku Solver */
#include <iostream>
#include <cmath>
using namespace std;

bool RakhSakteHai(int mat[][9], int i, int j, int n, int number) //Most IMPORTANT FUNCTION 
{
	for(int k=0; k<n; k++)
	{
		// ROW and COLUMN check
		if(mat[k][j]==number || mat[i][k]==number)
			return false;
	}
	int rootn = sqrt(n);
	int sub_x = (i/rootn)*rootn;      // Determining Index of First Box of
	int sub_y = (j/rootn)*rootn;	  //  the Sub_Matrix

	for(int x = sub_x ; x < sub_x+rootn ; x++ )
	{
		for(int y = sub_y ; y < sub_y+rootn ; y++)
		{
			if(mat[x][y]==number)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int mat[][9],int i, int j, int n)
{
	// Base Case
	if(i==n)
	{
		// Printing the Matrix
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}

	// Row end Case -- Moving to the next bottom Row
	if(j==n)
	{
		return solveSudoku(mat,i+1,0,n);
	}

	// Skipping the pre-filled cells
	if(mat[i][j]!=0)
	{
		return solveSudoku(mat,i,j+1,n);
	}

	// Recursive Case
	// Filling the cells with possible options

	for(int number=1; number<=n; number++)
	{
		if(RakhSakteHai(mat,i,j,n,number))
		{
			// Assuming its kept at Right Position
			mat[i][j]=number;

			bool AageSolveKarPaye = solveSudoku(mat,i,j+1,n);
			if(AageSolveKarPaye)
				return true;
		}
	}
	// Backtracking here 
	mat[i][j]=0;
	return false;

}
int main()
{
	int mat[9][9] = {
						{5,3,0,0,7,0,0,0,0},
						{6,0,0,1,9,5,0,0,0},
						{0,9,8,0,0,0,0,6,0},
						{8,0,0,0,6,0,0,0,3},
						{4,0,0,8,0,3,0,0,1},
						{7,0,0,0,2,0,0,0,6},
						{0,6,0,0,0,0,2,8,0},
						{0,0,0,4,1,9,0,0,5},
						{0,0,0,0,8,0,0,7,9},
	};
	solveSudoku(mat,0,0,9);
	return 0;
}







