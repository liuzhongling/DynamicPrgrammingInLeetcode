#include <iostream>
using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}
/*
int min(int x, int y) {
	return x < y ? x : y;
}
*/


int max(int x, int y) {
	return x>y ? x : y;
}

int maxprofit(int prices[], int len) {
	int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
	for (int i = 0; i < len; i++) {
		buy1 = max(buy1, -prices[i]); //��¼֮ǰ����������˵Ĺɼ�
		sell1 = max(sell1, buy1 + prices[i]);  //��¼֮ǰ������ֻ����1���������������

		buy2 = max(buy2, sell1 - prices[i]);  //��¼֮ǰ���Ƚ���1�ν��׻���������� �����Ǵν��׺�����˹ɼ�ʱʣ��ľ�����
		sell2 = max(sell2, buy2 + prices[i]); //��¼֮ǰ�����2���������׵��������
	}

	return sell2;
}
/*
int main(void) {
	int arr[] = { 3, 3, 5, 0, 0, 3, 1, 4 };
	int len = getArrayLen(arr);
	cout << len;
	int output = maxprofit(arr, len);
	cout << output;
	system("pause");
}
*/