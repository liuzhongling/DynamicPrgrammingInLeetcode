/*
Define S = [s,n] as the string S which consists of n connected strings s.
For example, ["abc", 3] ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2
if we can remove some characters from s2 such that it becomes s1. For example, 
¡°abc¡± can be obtained from ¡°abdbec¡± based on our definition, but it can not
be obtained from ¡°acbbe¡±.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) 
and two integers 0 ¡Ü n1 ¡Ü 106 and 1 ¡Ü n2 ¡Ü 106. Now consider the strings S1 and S2,
where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be 
obtained from S1.

Example:

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2


I didn't come up with any good solution so I tried brute force. Key points:

How do we know "string s2 can be obtained from string s1"? Easy, 
use two pointers iterate through s2 and s1. If chars are equal, 
move both. Otherwise only move pointer1.
We repeat step 1 and go through s1 for n1 times and count how many 
times can we go through s2.
Answer to this problem is times go through s2 divide by n2.



class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        
        int count1 = 0, count2 = 0, i = 0, j = 0;
        
        while(count1 < n1) {
            if (s1[i] == s2[j]) {
                // move j pointer in s2
                j++;
                if (j == len2) {
                    count2++;
                    j = 0;
                }
            }
            // move i pointer in s1
            i++;
            if (i == len1) {
                count1++;
                i = 0;
            }
        }
        
        return count2/n2;
    }
};
*/