#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int uniquepathWithObstacle(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> DP(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				DP[i][j] = 0;
			}
			else if (i == 0 && j == 0) {
				DP[i][j] = 1;
			}
			else if (i == 0) {
				DP[i][j] = DP[i][j - 1];
			}
			else if (j == 0) {
				DP[i][j] = DP[i - 1][j];
			}
			else {
				DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
			}
		}
	}
	return DP[m - 1][n - 1];
}
/*
int main() {
	vector<vector<int>> Arr(3, vector<int>(3));
	vector<int>::iterator it;
	for (int i = 0; i < Arr.size(); i++) {
		for (int j = 0; j < Arr[i].size(); j++) {
			Arr[i][j] = 0;
		}
	}
	Arr[1][1] = 1;
	int res = uniquepathWithObstacle(Arr);
	cout << res;
	system("pause");
}
*/

