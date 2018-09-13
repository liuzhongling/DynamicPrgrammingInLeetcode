/*
#include<iostream>
using namespace std;
template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0])); //注意存储字符串的字 符数组末尾有一个'/0'字符，需要去掉它	，因此要return (sizeof(array) / sizeof(array[0]));
}

int main()
{
	int Array_Int[100];
	float Array_Float[100];
	cout << "int:" << getArrayLen(Array_Int) << endl;
	cout << "float:" << getArrayLen(Array_Float) << endl;
	return 0;
}
*/

/*
#include<iostream>
using namespace std;



void printLen(int arr[][5]){
	int len = sizeof(arr) / sizeof(int);
	cout << len;
}

int main()
{
	int p[3][5];
	int len = sizeof(p) / sizeof(int);
	int len2 = sizeof(p[0]) / sizeof(int);
	int len3 = len / len2;
	printLen(p);
	printf_s("数组的第一维长度是 %d，第二维长度是 %d\n", len3, len2);
	system("pause");
	return 0;
}
*/