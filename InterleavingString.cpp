#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	if (s3.length() != s1.length() + s2.length()) {
		return false;
	}

	vector<vector<bool>> table(s1.length() + 1, vector<bool>(s2.length() + 1));

	for (int i = 0; i < s1.length() + 1; i++){
		for (int j = 0; j < s2.length() + 1; j++) {
			if (i == 0 && j == 0) {
				table[i][j] = true;
			}
			else if (i == 0) {
				table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
			else if (j == 0) {
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			}
			else {
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
	}

	return table[s1.length()][s2.length()];
}

/*
int main() {
	// string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";

	bool res = isInterleave(s1, s2, s3);

	cout << res;

	system("pause");
}
*/