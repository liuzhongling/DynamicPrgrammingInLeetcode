#include <iostream>
#include <malloc.h>
using namespace std;

int maxMoney(int nums[], int len) {
	if (len == 0) return 0;
	if (len == 1) return nums[0];
	if (len == 2) {
		return nums[0] > nums[1] ? nums[0] : nums[1];
	}
	int *dp = (int *)malloc(len * sizeof(int));

	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	for (int i = 2; i < len; i++) {
		int temp = dp[i - 2] + nums[i];
		dp[i] = temp > dp[i - 1] ? temp : dp[i - 1];
	}
	return dp[len - 1];
}
/*
int main(void) {
	int arr[] = { 2, 7, 9, 3, 1 };

	int total = maxMoney(arr, 5);

	cout << total;
	system("pause");
}
*/