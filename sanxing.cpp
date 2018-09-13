#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <vector>

using namespace std;

/*
int main(void){ 
	printf("Input/r/n");
	int N; 
	string s = "aaaaaa";
	scanf_s("%d", &N); 
	if (N<3 || N>1000000) { 
		printf("The length of the nucleotides sequence is exceed."); 
		return 1; 
	} 
	char** seq = (char **)malloc(sizeof(char*)*N); 
	int i; 
	for (i = 0; i<N; i++) { 
		int n; scanf_s("%d", &n); 
		seq[i] = (char *)malloc(sizeof(char)* (n + 1));
		scanf_s("%s", seq[i]); 
	} 
	printf_s("Output/r/n"); 
	for (i = 0; i<N; i++) { 
		printf_s("Case #%d/r/n", i + 1); 
    } 
	
	for (i = 0; i<N; i++) { free(seq[i]); } 
	free(seq); 
	return 0; 
}
*/
/*
int main(void)
{
	char a, b, c;
	printf_s("please input num a:\n");
	scanf_s("%c", &a);
	getchar();
	printf_s("please input num b:\n");
	scanf_s("%c", &b);
	getchar();
	printf_s("please input num c:\n");
	scanf_s("%c", &c);
	printf_s("%c,%c,%c", a, b, c);
}
*/
/*
int main(void) {
	char str[1000];
	char str1[70];
    cin >> str;
	cin >> str1;
	cout << str << "  "<< str1;

	system("pause");
}
*/