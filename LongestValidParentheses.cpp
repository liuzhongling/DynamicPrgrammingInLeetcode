#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;

bool isValid(string s) {
	stack<char> stk;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] = '(') {
			stk.push('(');
		}
		else {
			if (!stk.empty() && stk.top() == '(') {
				stk.pop();
			}
			else {
				return false;
			}
		}
	}
	return stk.empty();
}


int longestValidParentheses1(string s) {
	int maxLen = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		for (int j = i + 2; j <= len; j += 2) {
			if (isValid(s.substr(i, j-i))) {
				int temp = j - i;
				maxLen = maxLen > temp ? maxLen : temp;
			}
		}
	}
	return maxLen;
}

int longestValidParentheses2(string s) {
	int maxLen = 0;
	stack<int> stk;
	stk.push(-1);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			stk.pop();
			if (stk.empty()) {
				stk.push(i);
			}
			else {
				int temp = i - stk.top();
				maxLen = maxLen > temp ? maxLen : temp;
			}
		}
	}
	return maxLen;
}

int longestValidParenthese3(string s) {
	int left = 0, right = 0, maxLen = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			left++;
		}
		else {
			right++;
		}
		if (left == right) {
			int temp = 2 * right;
			maxLen = maxLen > temp ? maxLen : temp;
		}
		else if (right >= left) {
			left = right = 0;
		}
	}
	left = right = 0;

	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == '(') {
			left++;
		}
		else {
			right++;
		}
		if (left == right) {
			int temp = 2 * left;
			maxLen = maxLen > temp ? maxLen : temp;
		}
		else if (left >= right) {
			left = right = 0;
		}
	}

	return maxLen;
}

int longestValidParentheseDP(string s) {
	int len = s.length();
	int *dp = new int[len];
	memset(dp, 0, sizeof(int)*len);
	int maxLen = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
			}
			else if (i - dp[i - 1]>0 && s[i - dp[i - 1] - 1] == '(') {
				dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			}
			maxLen = maxLen > dp[i] ? maxLen : dp[i];
		}
	}
	return maxLen;
}

// ref https://leetcode.com/problems/longest-valid-parentheses/solution/
/*
int main() {
    // string a = "()(()))";
	string a = "())((())";
	cout << a << endl;
	int maxLen = longestValidParentheseDP(a);
	cout << maxLen;
	system("pause");
}
*/
