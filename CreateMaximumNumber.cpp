/*
Idea:

To find the maximum ,we can enumerate how digits we should get from nums1 ,
we suppose it is i.

So ,  the digits from nums2 is K ¨C i.

And we can use a stack to get the get maximum number(x digits) from one array.
£¨just like leetcode Remove Duplicate Letters£©

OK, Once we choose two maximum subarray , we should combine it to the answer.

It is just like merger sort, but we should pay attention to the case: the two digital are equal.

we should find the digits behind it to judge which digital we should choose now.

In other words,we should judge which subarry is bigger than the other.

That¡¯s all.

The algorithm is O((m+n)^3) in the worst case.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool greater(vector<int> &a, int start1, vector<int> &b, int start2) {
	for (; start1 < a.size() && start2 < b.size(); start1++, start2++) {
		if (a[start1] > b[start2]) return true;
		if (a[start1] < b[start2]) return false;
	}

	return start1 != a.size();
}

vector<int> getMaxSubArray(vector<int> &nums, int k) {
	vector<int> res(k, 0);

	int n = nums.size();

	for (int i = 0, j = 0; i < n; i++) {
		while (j >0 && n - i + j > k && nums[i] > res[j - 1]) j--;
		if (j < k) {
			res[j++] = nums[i];
		}
	}
	return res;
}

vector<int> maxNumber(vector<int> &num1, vector<int> &num2, int k) {
	vector<int> ans(k, 0);
	for (int i = max(0, k - (int)num2.size()); i < min(k, (int)num1.size()); i++) {
		vector<int> res1 = getMaxSubArray(num1, i);
		vector<int> res2 = getMaxSubArray(num2, k - i);
		vector<int> res(k, 0);
		int pos1 = 0, pos2 = 0, tpos = 0;
		while (pos1 < res1.size() || pos2 < res2.size())
		{
			res[tpos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
		}
		if (!greater(ans, 0, res, 0))
			ans = res;
	}

	return ans;
}

/*
int main(void) {

}
*/