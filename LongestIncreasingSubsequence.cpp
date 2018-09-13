#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLIS(int nums[], int n) {
	int *dp = (int *)malloc(n * sizeof(int));

	dp[0] = 1;
	
	int ans = 0;

	for (int i = 1; i < n; i++) {
		int temp = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < nums[i]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;

		ans = max(ans, dp[i]);
	}
	return ans;
}

/*
int main() {
	int nums[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int output = lengthOfLIS(nums, 8);
	cout << output;
	system("pause");
}
*/
