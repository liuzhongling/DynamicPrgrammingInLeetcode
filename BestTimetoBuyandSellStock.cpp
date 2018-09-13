#include <iostream>
#include <algorithm>
using namespace std;

int maxProfitN(int prices[], int n) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	for (int i = 0; i < n; i++) {
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
}
/*
int main(void) {
	int arr[] = { 7, 1, 5, 3, 6, 4 };
	int max = maxProfitN(arr, 6);
	cout << max;
	system("pause");
}
*/