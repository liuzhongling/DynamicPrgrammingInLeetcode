/*
class Solution {
public:
	//DFS+DP�Ӻ���ǰ�з��ַ�����ͬʱʹ��map��¼ÿ���ַ���
	//�����зֳ����е��ֵ��ַ�������ϣ����ⳬʱ
	map<string, vector<string>> mp;
	vector<string> dfs(string s, unordered_set<string> &dict)
	{
		//ǰ���Ѿ���������s��ͬ���ַ�����������ϣ�����ֱ�ӷ���
		if (mp.count(s))
			return mp[s];
		vector<string> ret;
		//�����ǰ��s�Ѿ������ֵ��У�������һ�ֵ�ǰ�ַ�����������
		if (dict.count(s))
			ret.push_back(s);
		for (int i = 1; i<s.length(); i++)
		{
			string postStr = s.substr(i);
			//�жϴӵ�ǰλ�õ�ĩβ��ȡ���ַ����Ƿ����ֵ��У�����
			//��ǰ��s�ַ������ܲ�ֵ���ϣ�����ǰ���ַ��������+��ǰ��ȡ�ĺ����ַ���
			if (dict.count(postStr))
			{
				vector<string> preVec = dfs(s.substr(0, i), dict);
				//��ǰ�淵�ص��ַ��������п�����϶����ϵ�ǰ�ĺ��������ֵ��е��ַ���
				for (int j = 0; j<preVec.size(); j++)
				{
					preVec[j] = preVec[j] + " " + postStr;
				}
				//��ǰ����ϵ��ַ������뵽��ǰs�����vector�У�
				//������vector��ǰ��(�������˳����𰸲�һ��)
				ret.insert(ret.begin(), preVec.begin(), preVec.end());
			}
		}
		//��¼���ַ���s���������
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