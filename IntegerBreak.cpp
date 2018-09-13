#include <iostream>
#include <algorithm>
using namespace std;

int integerBreak(int n) {
	int *dp = (int *)malloc((n + 1)*sizeof(int));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[4] = 4;
	for (int i = 5; i <= n; i++) {
		dp[i] = 3 * max(i - 3, dp[i - 3]);
	}
	return dp[n];
}

int integerBreak2(int n) {
	if (n == 2) return 2;
	if (n == 3) return 2;
	int product = 1;
	while (n > 4)
	{
		product *= 3;
		n -= 3;
	}
	product *= n;
	return product;
}
/*
int main(void) {
	int num = integerBreak2(10);
	cout << num;
	system("pause");
}
*/

