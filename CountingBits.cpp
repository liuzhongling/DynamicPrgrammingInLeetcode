#include <iostream>
using namespace std;

int* countBits(int num) {
	int *dp = (int *)malloc((num + 1)*sizeof(int));
	dp[0] = 0;
	for (int i = 1; i <= num; i++) {
		dp[i] = dp[i >> 1] + i % 2;
	}
	return dp;
}
/*
int main() {
	int num = 5;
	int* arr = countBits(num);

	for (int i = 0; i <= num; i++) {
		cout << arr[i];
	}
	system("pause");
}
*/