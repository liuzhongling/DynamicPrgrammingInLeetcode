/*
class Solution {
public:
	//DFS+DP从后往前切分字符串，同时使用map记录每段字符串
	//所能切分成所有的字典字符串的组合，避免超时
	map<string, vector<string>> mp;
	vector<string> dfs(string s, unordered_set<string> &dict)
	{
		//前面已经遍历过与s相同的字符串的所有组合，这里直接返回
		if (mp.count(s))
			return mp[s];
		vector<string> ret;
		//如果当前的s已经是在字典中，则增加一种当前字符串的组成组合
		if (dict.count(s))
			ret.push_back(s);
		for (int i = 1; i<s.length(); i++)
		{
			string postStr = s.substr(i);
			//判断从当前位置到末尾截取的字符串是否在字典中，若是
			//则当前的s字符串所能拆分的组合，即是前面字符串的组合+当前截取的后半段字符串
			if (dict.count(postStr))
			{
				vector<string> preVec = dfs(s.substr(0, i), dict);
				//对前面返回的字符串的所有可能组合都加上当前的后半段已在字典中的字符串
				for (int j = 0; j<preVec.size(); j++)
				{
					preVec[j] = preVec[j] + " " + postStr;
				}
				//将前后组合的字符串加入到当前s的组合vector中，
				//并放在vector最前面(否则，输出顺序与答案不一致)
				ret.insert(ret.begin(), preVec.begin(), preVec.end());
			}
		}
		//记录下字符串s的所有组合
		mp[s] = ret;
		return ret;
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		if (s.length() == 0)
			return vector<string>();
		return dfs(s, dict);
	}
};

*/