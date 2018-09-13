/*
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as 
one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of 
ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.


Here, I try to provide not only code but also the steps and thoughts of solving this problem completely which can also be applied to many other DP problems.

(1) Try to solve this problem in Backtracking way, because it is the most straight-forward method.

 E.g '12*3'
                   12*3
              /             \
           12*(3)           12(*3) 
         /     \            /      \
    12(*)(3)  1(2*)(3)  1(2)(*3)   ""
      /    \      \       /
1(2)(*)(3) ""     ""     ""   
    /
   ""
(2) There are many nodes visited multiple times, like 12 and 1. Most importantly, the subtree of those nodes are "exactly" the same. The backtracking solution possibly can be improved by DP. Try to merge the same nodes.

        12*3
        /  \
      12*  |
       | \ |
       |  12
       | / |
       1   |
        \  |
          ""
(3) Successfully merge those repeated nodes and find out the optimal substructure, which is:

      current state = COMBINE(next state ,  next next state)
      e.g
              12* 
              / \    
            COMBINE (few different conditions)
            /     \       
           12      1
Therefore, we can solve this problem by DP in bottom-up way instead of top-down memoization.
Now, we formulate the optimal substructure:

    dp[i] = COMBINE dp[i-1] and dp[i-2]
where dp[i] --> number of all possible decode ways of substring s(0 : i-1). Just keep it in mind.
But we need to notice there are some different conditions for this COMBINE operation.

(4) The pseudo code of solution would be:
*/
/*
Solution{
    initial conditions 
    dp[0] = ??
       :

     bottom up method 
    foreach( i ){
        dp[i] = COMBINE dp[i-1] and dp[i-2] ;
    }

    Return 
    return dp[last];
}
The COMBINE part will be something like:

    // for dp[i-1]
    if(condition A)
        dp[i] +=??  dp[i-1];
    else if(condition B)
        dp[i] +=??  dp[i-1];
            :
            :

     // for dp[i-2]
    if(condition C)
        dp[i] +=?? dp[i-2];
    else if(condition D)   
        dp[i] +=?? dp[i-2];
             :
(5) The core step of this solution is to find out all possible conditions and their corresponding operation of combination.

        For dp[i-1]:

                  /           \
                 /             \
            s[i-1]='*'    s[i-1]>0     
                |               |
          + 9*dp[i-1]        + dp[i-1]

             
        For dp[i-2]:

                   /                                  \
                  /                                    \  
              s[n-2]='1'||'2'                         s[n-2]='*'
              /            \                       /             \     
        s[n-1]='*'         s[n-1]!='*'          s[n-1]='*'       s[n-1]!='*'
         /       \               |                  |              /         \
  s[n-2]='1'  s[n-2]='2'   num(i-2,i-1)<=26         |         s[n-1]<=6    s[n-1]>6
      |            |             |                  |              |            |
 + 9*dp[i-2]   + 6*dp[i-2]     + dp[i-2]       + 15*dp[i-2]    + 2*dp[i-2]   + dp[i-2]
(6) Fill up the initial conditions before i = 2.
Because we need to check if num(i-2,i-1)<=26 for each i, we make the bottom-up process to begin from i=2. Just fill up the dp[0] and dp[1] by observation and by the definition of dp[i] --> number of all possible decode ways of substring s(0 : i-1).

         dp[0]=1;
         /      \
    s[0]=='*'  s[0]!='*'
        |         |
    dp[1]=9     dp[1]=1





    int numDecodings(string s) {
        int n = s.length();
        if (n >= 1 && s[0] == '0' ) return 0;
        vector<long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;
        
        for(int i = 2; i <= n; i++) {
            // for dp[i-1];
            if (s[i-1] == '*') {
                dp[i] += 9 * dp[i-1];
            } else if (s[i-1] - '0' > 0) {
                dp[i] += dp[i-1];
            }
            
            // for dp[i-2];
            
            if (s[i-2] == '*') {
                if (s[i-1] == '*') {
                    dp[i] += 15 * dp[i-2];
                } else {
                    if (s[i-1] - '0' <= 6) {
                        dp[i] += 2 * dp[i-2];
                    } else {
                        dp[i] += dp[i-2];
                    }
                }
                
            } else if (s[i-2] == '1' || s[i-2] == '2'){
                if (s[i-1] == '*') {
                    if (s[i-2] == '1') {
                        dp[i] += 9 * dp[i-2];
                    } else {
                        dp[i] += 6 * dp[i-2];
                    }
                } else {
                    if ((s[i-2] - '0') * 10 + (s[i-1] - '0') <= 26) {
                        dp[i] += dp[i-2];
                    }
                }
            }
            
            dp[i] = dp[i] % 1000000007;
        }
        
        return (int)dp[n];
    }

*/