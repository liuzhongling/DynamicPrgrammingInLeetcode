#include <iostream>
#include <malloc.h>
using namespace std;

/*Really smart solution, only freaking genius can come up with this idea...
It spends me some time to understand throughly about this.
Here is some simple math to prove the different loop case for even palindrome 
and odd palindrome, hope it helps:
Even case: Diameter = (i+j) - (i-j) = 2j, j = 0, 1, 2... the diameter here is 
even such as 0, 2,4... the for loop starts at j=0.
Odd case: Diameter = (i+j) - (i-j+1) = 2j-1, j = 1, 2, 3... the diameter here 
is odd such as 1,3,5...the for loop starts at j=1.*/

int mincut(string s) {
	int n = s.size();

	int *dp = (int *)malloc(sizeof(int)*(n+1));

	for (int i = 0; i <= n; i++) {
		dp[i] = i - 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
			dp[i + j + 1] = dp[i + j + 1] < (1 + dp[i - j]) ? dp[i + j + 1] : 1 + dp[i - j];
		}

		for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) {
			dp[i + j + 1] = dp[i + j + 1] < (dp[i - j + 1] + 1) ? dp[i + j + 1] : dp[i - j + 1] + 1;
		}
	}
	return dp[n];

}

/*
int main() {
	string s = "aabac";
	int num = mincut(s);
	cout << num;
	system("pause");

	// 二位数组
	int m = 3;
	int n = 3;
	int **array;
	array = (int **)malloc(m*sizeof(int*));

	for (int i = 0; i < m; i++) {
		array[i] = (int *)malloc(n*sizeof(int));
	}
	
}

*/

