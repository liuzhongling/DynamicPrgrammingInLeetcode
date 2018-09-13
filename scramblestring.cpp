/*
������
���������google�������⡣����һ���ַ����кܶ��ֶ����ʾ����ò�ƺ����ж������ַ����Ƿ�����������ı任��
�Ը���������ķ����ǴӼ򵥵�������˼�����Ӷ��ҳ����ɡ�
�ȿ���������
�ַ�������Ϊ1�������ԣ������ַ���������ȫ��ͬ�ſ��ԡ�
�ַ�������Ϊ2����s1="ab", s2ֻ��"ab"����"ba"�ſ��ԡ�
�������ⳤ�ȵ��ַ��������ǿ��԰��ַ���s1��Ϊa1,b1�������֣�s2��Ϊa2,b2�������֣����㣨(a1~a2) && (b1~b2)������ ��(a1~b2) && (a1~b2)��

��ˣ������ҵ��˽�������˼·���������ǳ����õݹ���д��

�ⷨһ���ݹ飩:
�����ַ��������Ƶıر������Ǻ�����ͬ���ַ������򵥵������ǰ������ַ������ַ������Ȼ��Ƚ��Ƿ���ͬ��
����������Ϳ��Դ��ļ��ٵݹ������
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
����⿴�����ǱȽϸ��ӵģ������brute force��ÿ�����иȻ��ݹ���⣬��һ���Ƕ���ʽ�ĸ��Ӷȣ�һ����˵�ⲻ�����Թ���Ҫ�Ĵ𰸡�
����ʵ��һ����ά��̬�滮����Ŀ���������ά����res[i][j][n]������i��s1����ʼ�ַ���j��s2����ʼ�ַ���
��n�ǵ�ǰ���ַ������ȣ�res[i][j][len]
��ʾ������i��j�ֱ�Ϊs1��s2���ĳ���Ϊlen���ַ����ǲ��ǻ�Ϊscramble��
����ά�������ǽ�������������ʽ��Ҳ������ô������ʷ��Ϣ���õ�res[i][j][len]���ж�����ǲ������㣬
��ʵ���������ǰѵ�ǰs1[i...i+len-1]�ַ���
��һ���ֳ������֣�Ȼ��������������һ������ߺ�s2[j...j+len-1]��߲����ǲ���scramble���Լ��ұߺ�s2[j...j+len-1]
�ұ߲����ǲ���scramble��
�ڶ����������ߺ�s2[j...j+len-1]�ұ߲����ǲ���scramble���Լ��ұߺ�s2[j...j+len-1]��߲����ǲ���scramble��
����������������һ�ֳ�����˵��
s1[i...i+len-1]��s2[j...j+len-1]��scramble�ġ��������ж���Щ���Ҳ����ǲ���scramble����������ʷ��Ϣ�ģ�
��Ϊ����С��n������������Ƕ���ǰ����
����ˣ�Ҳ���ǳ����������ѭ������
����˵������һ�������������s1[i...i+len-1]������len-1������������Щ������ֻҪ��һ�ֳ�����
��ô����������scramble�ġ�
�ܽ���������ʽ��res[i][j][len] = || (res[i][j][k]&&res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k]) 
��������1<=k<len��Ҳ����
��������len-1�������Ľ��������㡣��Ϊ��Ϣ���Ǽ�����ģ�����ÿ������ֻ��Ҫ��������������ɣ�
���������ʽ����ҪO(len)����Ϊlen-1����������
�����ʱ�临�Ӷ���Ϊ����ά��̬�滮����Ҫ����ѭ��������ÿһ����Ҫ����ʱ��������ʽ��������O(n^4)��
��Ȼ�Ѿ��Ƚϸ��ˣ��������ٲ���ָ�������ģ�
��̬�滮�����кܴ����µģ��ռ临�Ӷ���O(n^3)���������£�
*/

bool isScrambleDp(string s1, string s2) {
	if (s1.size() == 0) return true;
	// dp[i][j][len]��ʾ������i��j�ֱ�Ϊs1��s2���ĳ���Ϊlen���ַ����ǲ��ǻ�ΪScramble String
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