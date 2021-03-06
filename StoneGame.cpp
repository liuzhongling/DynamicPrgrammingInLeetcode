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


对于动态规划的题，一般求什么就设什么。在这里我们设dp[i][j]表示从piles[i]到piles[j]你可以比对手多得的最多的分数。这样我们的最终目标是dp[0][n-1]。现在我们需要确定转移方程和初始条件。
在piles[i]~piles[j]中，你可以选择piles[i]或者piles[j]：
如果你选择了piles[i]，那么你的对手就会从piles[i+1]~piles[j]中得到最多的分数，分数差值为piles[i]-dp[i+1][j].(题目要求都发挥最佳水平，所以对于对手而言dp的含义一样。,他会从剩下的piles中选择最多的分数，所以两者做减法。）
如果你选择了piles[j],分数差值为piles[j] - dp[i][j-1].

所以状态转移方程为：
dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

初始条件为：
当 i == j 时， dp[i][i] = piles[i]
根据上述思路可以很简单的写出代码：

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
即使最开始知道了状态转移方程，但循环体（特别是循环变量和限制条件仍然存在问题）。
最开始时并没有理解为什么要这么写，等到再一次碰到类似题目的时候发现自己仍然写不出来，
才知道自己并没有理解真正的题解内涵。我们最开始设置当i==j时，dp[i][i]=piles[i].这是初始条件。
然后他的类推方式是通过第一层循环中的d的改变来不断调整i，j之间元素的个数。即d == 1时，
我们两个两个一组进行计算，d == 2时，我们三个三个一组进行计算，以此类推。最终得出最后的答案。
如图所示：

---------------------

*/