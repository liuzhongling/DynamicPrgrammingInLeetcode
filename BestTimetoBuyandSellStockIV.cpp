#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

/*
It's not difficult to get the DP recursive formula:

dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]

min[k] = min(min[k], prices[i] - dp[k-1])
dp[k] = max(dp[k], prices[i] - min[k])

For k transactions, on i-th day,
if we don't trade then the profit is same as previous day dp[k, i-1];
and if we bought the share on j-th day where j=[0..i-1],
then sell the share on i-th day then the profit is prices[i] - prices[j] + dp[k-1, j-1] .
Actually j can be i as well. When j is i, 
the one more extra item prices[i] - prices[j] + dp[k-1, j] = dp[k-1, i] 
looks like we just lose one chance of transaction.
*/

int maxProfit(int K, int prices[], int m) {
	if (m == 0) return 0;

	int *dp = (int *)malloc((K+1) * sizeof(int));
	int *mini = (int *)malloc((K+1) * sizeof(int));
	for (int i = 0; i <= K; i++) {
		dp[i] = 0;
		mini[i] = prices[0];
	}

	for (int i = 0; i < m; i++) {
		for (int k = 1; k <= K; k++) {
			mini[k] = mini[k] < (prices[i] - dp[k - 1]) ? mini[k] : (prices[i] - dp[k - 1]);
			dp[k] = dp[k] > (prices[i] - mini[k]) ? dp[k] : (prices[i] - mini[k]);
		}
	}
	return dp[K];
}

/*

int main() {
	int arr[] = { 3, 2, 6, 5, 0, 3 };

	int stock = maxProfit(2, arr, 6);

	cout << stock;

	system("pause");
}

*/