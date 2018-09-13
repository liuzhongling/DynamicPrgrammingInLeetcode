#include <iostream>
#include <algorithm>
using namespace std;

int robber(int nums[], int left, int right) {
	int pre = 0, cur = 0;

	for (int i = left; i <= right; i++) {
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	}

	return cur;
}
int rob(int nums[], int n) {
	if (n < 2) return n ? nums[0] : 0;

	return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}

/*
int main() {
	int arr[] = { 1,2,3,1 };
	int money = rob(arr, 4);

	cout << money;

	system("pause");
}
*/