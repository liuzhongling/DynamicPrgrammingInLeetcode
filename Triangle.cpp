#include <iostream>
#include <vector>
using namespace std;

int min(int x, int y) {
	return x < y ? x : y;
}


int minimumTotal(vector<vector<int>> &triangle) {
	vector<int> mini = triangle[triangle.size() - 1];
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
		}
	}
	return mini[0];
}

/*
int main(void) {
	
}
*/