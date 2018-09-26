/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.



Example 1:

Input: [5,3,4,5]
Output: true
Explanation:
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.


Note:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.


���ڶ�̬�滮���⣬һ����ʲô����ʲô��������������dp[i][j]��ʾ��piles[i]��piles[j]����Աȶ��ֶ�õ����ķ������������ǵ�����Ŀ����dp[0][n-1]������������Ҫȷ��ת�Ʒ��̺ͳ�ʼ������
��piles[i]~piles[j]�У������ѡ��piles[i]����piles[j]��
�����ѡ����piles[i]����ô��Ķ��־ͻ��piles[i+1]~piles[j]�еõ����ķ�����������ֵΪpiles[i]-dp[i+1][j].(��ĿҪ�󶼷������ˮƽ�����Զ��ڶ��ֶ���dp�ĺ���һ����,�����ʣ�µ�piles��ѡ�����ķ�����������������������
�����ѡ����piles[j],������ֵΪpiles[j] - dp[i][j-1].

����״̬ת�Ʒ���Ϊ��
dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

��ʼ����Ϊ��
�� i == j ʱ�� dp[i][i] = piles[i]
��������˼·���Ժܼ򵥵�д�����룺

---------------

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int d = 1; d < n; d++)
            for (int i = 0; i < n - d; i++)
                dp[i][i + d] = max(piles[i] - dp[i + 1][i + d], piles[i + d] - dp[i][i + d - 1]);
        return dp[0][n - 1] > 0;
    }
};

---------------------
��ʹ�ʼ֪����״̬ת�Ʒ��̣���ѭ���壨�ر���ѭ������������������Ȼ�������⣩��
�ʼʱ��û�����ΪʲôҪ��ôд���ȵ���һ������������Ŀ��ʱ�����Լ���Ȼд��������
��֪���Լ���û���������������ں��������ʼ���õ�i==jʱ��dp[i][i]=piles[i].���ǳ�ʼ������
Ȼ���������Ʒ�ʽ��ͨ����һ��ѭ���е�d�ĸı������ϵ���i��j֮��Ԫ�صĸ�������d == 1ʱ��
������������һ����м��㣬d == 2ʱ��������������һ����м��㣬�Դ����ơ����յó����Ĵ𰸡�
��ͼ��ʾ��

---------------------

*/