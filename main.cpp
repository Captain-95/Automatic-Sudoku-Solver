#include<bits/stdc++.h>
using namespace std;

#define N 9

void print_the_sudoku(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

bool correct_pos(int grid[N][N], int row,int col, int num)
{

	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	int startRow = row - row % 3,
			startCol = col - col % 3;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j + startCol] == num)
				return false;

	return true;
}


bool sudoku_solver(int grid[N][N], int row, int col)
{

	if (row == N - 1 && col == N)
		return true;


	if (col == N) {
		row++;
		col = 0;
	}

	if (grid[row][col] > 0)
		return sudoku_solver(grid, row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		

		if (correct_pos(grid, row, col, num))
		{
			
			grid[row][col] = num;

			if (sudoku_solver(grid, row, col + 1))
				return true;
		}
		
		grid[row][col] = 0;
	}
	return false;
}

int main()
{
	// 0 means unassigned cells
	int grid[N][N]; 

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<"Enter value in position grid["<<i+1<<","<<j+1<<"] :- ";
            cin>>grid[i][j];
        }
    }

	if (sudoku_solver(grid, 0, 0))
		print_the_sudoku(grid);
	else
		cout << "There is no solution exists for this sudoku ☹️" << endl;

	return 0;
}
