#include <iostream>
using namespace std;

class NumArray {
public:
	NumArray(int nums[], int n) {
		psum = (int *)malloc((n + 1)*sizeof(int));
		psum[0] = 0;
		for (int i = 1; i <= n; i++) {
			psum[i] = psum[i - 1] + nums[i - 1];
		}
	}
	int sumRange(int i, int j) {
		return psum[j + 1] - psum[i];
	}
private:
	int *psum;
};

/*
int main(void) {
	int arr[] = { -2, 0, 3, -5, 2, -1 };
	NumArray numarr = NumArray(arr, 6);
	cout << numarr.sumRange(0, 2) << endl;
	cout << numarr.sumRange(2, 5) << endl;
	cout << numarr.sumRange(0, 5) << endl;

	system("pause");
}
*/