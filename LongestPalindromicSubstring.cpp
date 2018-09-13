#include <iostream>
#include <string>
using namespace std;

string longestPalindromicSubString(string s) {
	if (s.size() == 0) return "";
	int i = 0, j = 0;
	int n = s.length();
	bool **P = new bool*[n];
	for (int i = 0; i < n; i++) {
		P[i] = new bool[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			P[i][j] = false;
		}
	}
	for (int x = 0; x < n; x++) {
		P[x][x] = true;
		if (x == n - 1) break;
		P[x][x + 1] = (s[x] == s[x + 1]);
	}

	// dp
	for (int i = n - 3; i >= 0; i--){
		for (int j = i + 2; j < n; j++) {
			P[i][j] = (P[i + 1][j - 1] && s[i] == s[j]);
		}
	}

	int max = 0;
	string maxString = "";

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (P[i][j] == true && j - i + 1> max) {
				max = j - i + 1;
				maxString = s.substr(i, j - i + 1);
			}
		}
	}
	return maxString;
}

int expandAroundCenter(string s, int left, int right) {
	int L = left, R = right;
	while (L >= 0 && R < s.length() && s[L] == s[R]) {
		L--;
		R++;
	}
	return R - L - 1;
}


string longestPalindromicSubString2(string s) {
	int n = s.length();
	if (n <= 0) return "";
	int start = 0, end = 0;
	for (int i = 0; i < n; i++) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		int len = len1>len2 ? len1 : len2;
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end - start + 1);
}

/*

int main() {
	string s = "bcabbacd";
	// string maxStr = longestPalindromicSubString(s);
	string maxStr = longestPalindromicSubString2(s);
	cout << maxStr;

	system("pause");
}

*/
