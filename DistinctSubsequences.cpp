#include <iostream>
#include <vector>
using namespace std;
/*
Well, a dynamic programming problem.Let's first define its state dp[i][j] to 
be the number of distinct subsequences of t[0..i - 1]
in s[0..j - 1]. Then we have the following state equations:

General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.
*/

int numDistinct(string s, string t)  {
	int m = t.length(), n = s.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int j = 0; j <= n; j++) {
		dp[0][j] = 1;
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
		}
	}

	return dp[m][n];
}

/*

int main(void) {
	string s = "babgbag";
	string t = "bag";
	int count = numDistinct(s, t);
	cout << count;

	system("pause");
}

*/