#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n)
{
	if (x < n && y < n && arr[x][y] == 1) {
		return true;
	}
	return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solarr)
{
	if (x == n - 1 && y == n - 1) {
		solarr[x][y] = 1;
		return true;
	}


	if (isSafe(arr, x, y, n)) {
		solarr[x][y] = 1;
		if (ratinMaze(arr, x + 1, y, n, solarr)) {
			return true;
		}
		if (ratinMaze(arr, x, y + 1, n, solarr)) {
			return true;
		}
		solarr[x][y] = 0;
		return false;
	}
	return false;
}

int main()
{
	int n;
	cout << "Enter Size of 2D Array: ";
	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	cout << endl;
	cout << "Enter 2D Array (MAZE) \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << endl << endl;
	int** solarr = new int* [n];
	for (int i = 0; i < n; i++) {
		solarr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			solarr[i][j] = 0;
		}
	}
	if (ratinMaze(arr, 0, 0, n, solarr)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << solarr[i][j]<<" ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Maze Is not Correct i.e there is no Path \n";
	}
	return 0;
}


/*
	1 0 1 0 1
	1 1 1 1 1
	0 1 0 1 0
	1 0 0 1 1
	1 1 1 0 1

	---MAZE---

	0 are blocked path 
	RAT move only downward or right

	1 0 0 0 0
	1 1 1 1 0
	0 0 0 1 0
	0 0 0 1 1
	0 0 0 0 1

  ---SOLUTION---

*/