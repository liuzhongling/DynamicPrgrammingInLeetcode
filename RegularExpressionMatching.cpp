#include <iostream>
#include <vector>
using namespace std;

/*
1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
3, If p.charAt(j) == '*':
here are two sub conditions:
1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  
//in this case, a* only counts as empty
2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
*/
bool isMatchCs(string s, string p) {
	/**
	* f[i][j]: if s[0..i-1] matches p[0..j-1]
	* if p[j - 1] != '*'
	*      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
	* if p[j - 1] == '*', denote p[j - 2] with x
	*      f[i][j] is true iff any of the following is true
	*      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
	*      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
	* '.' matches any single character
	*/
	int m = s.size(), n = p.size();
	vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

	f[0][0] = true;
	for (int i = 1; i <= m; i++)
		f[i][0] = false;
	// p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
	for (int j = 1; j <= n; j++)
		f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	if (p[j - 1] != '*')
		f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
	else
		// p[0] cannot be '*' so no need to check "j > 1" here
		f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

	return f[m][n];
}

bool isMatch(string s, string p) {
	if (s.length() == 0 || p.length() == 0) {
		return false;
	}

	int m = s.length(), n = p.length();

	bool **dp = (bool **)malloc((m + 1)*sizeof(bool*));

	for (int i = 0; i <= m; i++) {
		dp[i] = (bool *)malloc((n + 1)*sizeof(bool));
	}

	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		if (p[i - 1] == '*' && dp[0][i - 2]) {
			dp[0][i] = true;
		}
	}

	for (int i = 1; i < m; i++) {
		dp[i][0] = false;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}

			if (p[j - 1] = '*') {
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
				}
			}
			else {
				dp[i][j] = dp[i][j - 2];
			}
		}
	}
}
