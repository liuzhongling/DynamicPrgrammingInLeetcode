#include <iostream>
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;

	int p2 = 0, p3 = 0, p5 = 0;

	int *num = (int *)malloc(n * sizeof(int));
	num[0] = 1;

	for (int i = 1; i < n; i++) {
		num[i] = min(num[p2] * 2, min(num[p3] * 3, num[p5] * 5));

		if (num[i] == num[p2] * 2) p2++;
		if (num[i] == num[p3] * 3) p3++;
		if (num[i] == num[p5] * 5) p5++;
	}
	return num[n - 1];
}
/*
int main(void) {
	int ugly = nthUglyNumber(10);
	cout << ugly;
	system("pause");
}
*/