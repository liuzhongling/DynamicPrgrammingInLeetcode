#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int coinChange(int coins[], int len,int amount) {
	int Max = amount + 1;
	vector<int> dp(amount + 1, Max);
	dp[0] = 0;
	for (int i = 0; i <= amount; i++) {
		for (int j = 0; j < len; j++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	return dp[amount] > amount ? -1 : dp[amount];
}
/*
int main(void) {
	int coins[] = { 2 };
	int output = coinChange(coins,1,3);
	cout << output;
	system("pause");
}
*/