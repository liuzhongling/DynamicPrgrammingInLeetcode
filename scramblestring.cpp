/*
分析：
这个问题是google的面试题。由于一个字符串有很多种二叉表示法，貌似很难判断两个字符串是否可以做这样的变换。
对付复杂问题的方法是从简单的特例来思考，从而找出规律。
先考察简单情况：
字符串长度为1：很明显，两个字符串必须完全相同才可以。
字符串长度为2：当s1="ab", s2只有"ab"或者"ba"才可以。
对于任意长度的字符串，我们可以把字符串s1分为a1,b1两个部分，s2分为a2,b2两个部分，满足（(a1~a2) && (b1~b2)）或者 （(a1~b2) && (a1~b2)）

如此，我们找到了解决问题的思路。首先我们尝试用递归来写。

解法一（递归）:
两个字符串的相似的必备条件是含有相同的字符集。简单的做法是把两个字符串的字符排序后，然后比较是否相同。
加上这个检查就可以大大的减少递归次数。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2) {
	if (s1 == s2) return true;

	int len = s1.length();
	int count[26] = { 0 };

	for (int i = 0; i < len; i++) {
		count[s1[i] - 'a']++;
		count[s2[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) return false;
	}

	for (int i = 1; i < len; i++) {
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
			return true;
	}
	return false;
}

/*
这道题看起来是比较复杂的，如果用brute force，每次做切割，然后递归求解，是一个非多项式的复杂度，一般来说这不是面试官想要的答案。
这其实是一道三维动态规划的题目，我们提出维护量res[i][j][n]，其中i是s1的起始字符，j是s2的起始字符，
而n是当前的字符串长度，res[i][j][len]
表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为scramble。
有了维护量我们接下来看看递推式，也就是怎么根据历史信息来得到res[i][j][len]。判断这个是不是满足，
其实我们首先是把当前s1[i...i+len-1]字符串
劈一刀分成两部分，然后分两种情况：第一种是左边和s2[j...j+len-1]左边部分是不是scramble，以及右边和s2[j...j+len-1]
右边部分是不是scramble；
第二种情况是左边和s2[j...j+len-1]右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。
如果以上两种情况有一种成立，说明
s1[i...i+len-1]和s2[j...j+len-1]是scramble的。而对于判断这些左右部分是不是scramble我们是有历史信息的，
因为长度小于n的所有情况我们都在前面求
解过了（也就是长度是最外层循环）。
上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要有一种成立，
那么两个串就是scramble的。
总结起来递推式是res[i][j][len] = || (res[i][j][k]&&res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k]) 
对于所有1<=k<len，也就是
对于所有len-1种劈法的结果求或运算。因为信息都是计算过的，对于每种劈法只需要常量操作即可完成，
因此求解递推式是需要O(len)（因为len-1种劈法）。
如此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，所以是O(n^4)。
虽然已经比较高了，但是至少不是指数量级的，
动态规划还是有很大有事的，空间复杂度是O(n^3)。代码如下：
*/

bool isScrambleDp(string s1, string s2) {
	if (s1.size() == 0) return true;
	// dp[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为Scramble String
	vector<vector<vector<bool>>> dp(s1.size(), vector<vector<bool>>(s2.size(),vector<bool>(s1.size() + 1, false)));

	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			dp[i][j][1] = s1[i] == s2[j];
		}
	}

	for (int len = 2; len <= s1.size(); ++len) {
		for (int i = 0; i < s1.size() - len + 1; ++i){
			for (int j = 0; j < s2.size() - len + 1; ++j) {
				for (int k = 1; k < len; ++k) {
					dp[i][j][len] = dp[i][j][len] ||
						dp[i][j][k] && dp[i + k][j + k][len - k] ||
						dp[i][j + len - k][k] && dp[i + k][j][len - k];
				}
			}
		}
	}
	return dp[0][0][s1.size()];
}
/*
int main() {
	string s1 = "great", s2 = "rgeat";

	bool res = isScrambleDp(s1, s2);
	cout << res;

	system("pause");
}
*/