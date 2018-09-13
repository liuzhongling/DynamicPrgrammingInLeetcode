#include <iostream>
#include <vector>
using namespace std;
/*
int min(int x, int y) {
	return (x < y) ? x : y;
}


int minPathSum(vector<vector<int>>& grid) {
	vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));
	int sum = 0;
	for (int i = 0; i < grid.size(); ++i) {
		sum += grid[i][0];
		memo[i][0] = sum;
	}
	sum = 0;
	for (int i = 0; i < grid[0].size(); ++i) {
		sum += grid[0][i];
		memo[0][i] = sum;
	}
	for (int i = 1; i < grid.size(); ++i) {
		for (int j = 1; j < grid[0].size(); ++j) {
			memo[i][j] = grid[i][j] + min(memo[i - 1][j], memo[i][j - 1]);
		}
	}
	return memo[grid.size() - 1][grid[0].size() - 1];
}

int main() {
	int arr[3][3] = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};

	vector<vector<int>> grid(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = arr[i][j];
		}
	}

	int minSum = minPathSum(grid);
	cout << minSum;
	system("pause");
}
*/
