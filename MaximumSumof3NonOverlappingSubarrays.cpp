/*

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed).
If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).


The question asks for three non-overlapping intervals with maximum sum of all 3 intervals.
If the middle interval is [i, i+k-1], where k <= i <= n-2k, the left interval has to be in 
subrange [0, i-1], and the right interval is from subrange [i+k, n-1].

So the following solution is based on DP.

posLeft[i] is the starting index for the left interval in range [0, i];
posRight[i] is the starting index for the right interval in range [i, n-1];
Then we test every possible starting index of middle interval, i.e. k <= i <= n-2k, and we
can get the corresponding left and right max sum intervals easily from DP. And the run time is O(n).

Caution. In order to get lexicographical smallest order, when there are two intervals with
equal max sum, always select the left most one. So in the code, the if condition is ">= tot" 
for right interval due to backward searching, and "> tot" for
left interval. Thanks to @lee215 for pointing this out!


Array left[i] stores the starting index of the max sum subarray before i
Array right[i] stores the starting index of the max sum subarray after i
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
	int n = nums.size();

	vector<int> sums(n, 0);
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	vector<int> res(3, 0);

	sums[0] = nums[0];

	for (int i = 1; i <n; i++) {
		sums[i] = sums[i-1] + nums[i];
	}

	int max = INT_MIN;

	// max sum index before i;
	for (int i = k - 1; i < n; i++) {
		int sum = sums[i] - sums[i - k + 1] + nums[i - k + 1]; // sum from i to (i - k + 1)
		if (sum > max) {
			max = sum;
			left[i] = i - k + 1;
		}
		else {
			left[i] = left[i - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << left[i] << endl;
	}

	// max sum index after j;
	max = INT_MIN;
	for (int i = n - k; i >= 0; i--) {
		int sum = sums[i + k - 1] - sums[i] + nums[i];
		if (sum >= max) {
			max = sum;
			right[i] = i;
		}
		else {
			right[i] = right[i + 1];
		}
	}


	max = INT_MIN;
	for (int i = k; i <= n - 2 * k; i++) {
		int lpos = left[i - 1];
		int rpos = right[i + k];

		int sum = sums[lpos + k - 1] - sums[lpos] + nums[lpos]; // max sum subarray on the left

		sum += sums[i + k - 1] - sums[i] + nums[i]; // middle sum;

		sum += sums[rpos + k - 1] - sums[rpos] + nums[rpos]; // max sum subarray on the right;

		if (sum > max) {
			max = sum;
			res[0] = lpos;
			res[1] = i;
			res[2] = rpos;
		}
	}

	return res;
}

int main() {
	int arr[] = { 7, 13, 20, 19, 19, 2, 10, 1, 1, 19 };
	vector<int> array(10, 0);

	for (int i = 0; i < 10; i++) {
		array[i] = arr[i];
	}

	vector<int> res = maxSumOfThreeSubarrays(array, 3);

	system("pause");
}

*/
