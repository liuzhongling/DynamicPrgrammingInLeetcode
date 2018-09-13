#include <iostream>
using namespace std;

bool check(char a) {
	return a != '0';
}

bool checkdb(char a, char b) {
	return a == '1' || (a == '2' && b <= '6');
}

int numDecodes(string s) {
	int len = s.length();
	if (len == 0 || s[0] == '0') {
		return 0;
	}

	if (len == 1 && check(s[0])) {
		return 1;
	}

	int *dp = (int *)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {
		dp[i] = 0;
	}

	dp[0] = 1;

	dp[1] = (check(s[1]) ? 1 : 0) + (checkdb(s[0], s[1]) ? 1 : 0);

	for (int i = 2; i < len; i++) {
		if (check(s[i])) {
			dp[i] = dp[i - 1];
		}

		if (checkdb(s[i - 1], s[i])) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[len - 1];
}
/*
int main(void) {
	string code = "226";
	cout << numDecodes(code);
	system("pause");
}
*/