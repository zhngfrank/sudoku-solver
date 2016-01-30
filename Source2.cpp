#include <iostream>

using namespace std;

const int N = 3,
SIZE = N*N;

int main()
{
	bool board[SIZE][SIZE][SIZE];
	int display[SIZE][SIZE] =
	{
	{-1, 1, 8, -1, -1, -1, 3, -1, -1},
	{-1, -1, -1, 4, -1, -1, 0, -1, -1},
	{-1, 3, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 3, 1, -1, -1, -1},
	{5, -1, -1, -1, -1, -1, -1, 6, -1},
	{4, -1, -1, -1, -1, -1, -1, -1, -1},
	{6, -1, -1, 2, -1, -1, -1, -1, 4},
	{-1, 0, -1, -1, 8, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, 5, -1}
	},
		i = 0, j = 0, k = 0, l = 0, m = 0,
		a = 0, b = 0, blank = 0,
		row = 0, colomn = 0, block = 0,
		filled = 17;
	
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				board[i][j][k] = true;
	/*do
	{
		i = j = k = SIZE;
		cin >> i >> j >> k;
		i--; j--; k--;

		if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && k >= 0 && k < SIZE
			&& display[i][j] == -1)
		{
			display[i][j] = k;
			filled++;
			cout << filled << " valid input entered." << endl;
		}
		else
		{
			cout << "Retype three valid inputs with 1<=i<=" << SIZE
				<< ", 1<=j<=" << SIZE 
				<< ", 1<=k<=" << SIZE << " (exit k=0): ";
		}
	} while (k != -1);*/

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (display[i][j] != -1)
			{
				for (k = 0; k < SIZE; k++)
				{
					board[i][k][(display[i][j])] = false;
					board[k][j][(display[i][j])] = false;
				}
				for (k = i - i % N; k < i - i % N + N; k++)
					for (l = j - j % N; l < j - j % N + N; l++)
					{
						board[k][l][(display[i][j])] = false;
					}
			}
		}
	}

	while (filled < SIZE*SIZE)
	{
		cout << endl;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
				cout << display[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		cout << filled << endl;

		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				colomn = a = b = 0;
				for (k = 0; k < SIZE; k++)
				{

					if (!board[j][k][i]) colomn++;
					else
					{
						blank = i;
						a = j;
						b = k;
					}
				}

				if (colomn == SIZE - 1)
				{
					display[a][b] = blank;
					filled++;
					for (k = 0; k < SIZE; k++)
					{
						board[a][k][blank] = false;
						board[k][b][blank] = false;
					}
					for (k = a - a % N; k < a - a % N + N; k++)
						for (l = b - b % N; l < b - b % N + N; l++)
						{
							board[k][l][blank] = false;
						}
				}

				row = a = b = 0;
				for (k = 0; k < SIZE; k++)
				{

					if (!board[k][j][i]) row++;
					else
					{
						blank = i;
						a = k;
						b = j;
					}
				}

				if (row == SIZE - 1)
				{
					display[a][b] = blank;
					filled++;
					for (k = 0; k < SIZE; k++)
					{
						board[a][k][blank] = false;
						board[k][b][blank] = false;
					}
					for (k = a - a % N; k < a - a % N + N; k++)
						for (l = b - b % N; l < b - b % N + N; l++)
						{
							board[k][l][blank] = false;
						}
				}

				for (k = 0; k < SIZE; k++)
				{
					block = a = b = 0;
					for (l = j - j % N; l < j - j % N + N; l++)
						for (m = k - k % N; m < k - k % N + N; m++)
						{
							if (!board[l][m][i]) block++;
							else
							{
								blank = i;
								a = l;
								b = m;
							}
						}

					if (block == SIZE - 1)
					{
						display[a][b] = blank;
						filled++;
						for (l = 0; l < SIZE; l++)
						{
							board[a][l][blank] = false;
							board[l][b][blank] = false;
						}
						for (l = a - a % N; l < a - a % N + N; l++)
							for (m = b - b % N; m < b - b % N + N; m++)
							{
								board[l][m][blank] = false;
							}
					}
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << display[i][j] << " ";
		cout << endl;
	}

//	system("pause");
	return 0;
}
