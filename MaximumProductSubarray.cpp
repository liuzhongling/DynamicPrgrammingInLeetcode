#include <iostream>
#include <malloc.h>
using namespace std;

int maxProduct(int A[], int n) {
	if (n == 0) return 0;

	int r = A[0];

	for (int i = 1, rmin = r, rmax = r; i < n; i++) {
		if (A[i] < 0) {
			int temp = rmin;
			rmin = rmax;
			rmax = temp;
		}
		
		int rmaxA = rmax * A[i];
		int rminA = rmin * A[i];
		rmax = A[i] > rmaxA ? A[i] : rmaxA;
		rmin = A[i] < rminA ? A[i] : rminA;

		r = r > rmax ? r : rmax;
	}
	return r;
}
/*
int main(void) {
	int arr[] = { 2, 3, -2, 4, -2 };

	int product = maxProduct(arr, 5);

	cout << product;

	system("pause");
}
*/