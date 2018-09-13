#include <iostream>
#include <algorithm>
using namespace std;

int numSquares(int n) {
	if (n <= 0) return 0;

	int *dp = (int *)malloc((n + 1) * sizeof(int));

	dp[0] = 0;

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int temp = INT_MAX;
		for (int j = 1; j*j <= i; j++) {
			temp = min(temp, dp[i - j*j] + 1);
		}
		dp[i] = temp;
	}
	return dp[n];
}

/*
int main(void) {
	int num = numSquares(13);
	cout << num;
	system("pause");
}
*/