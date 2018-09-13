/*

Thanks for the smart solution. Let me further explain it:

let one[i] be the number of non-consecutive-1 solutions with the i-th significant bit being 1;
let zero[i] be the number of non-consecutive-1 solutions with the i-th significant bit being 0;
the most tricky part is how to count the solutions smaller than num.
We first calculate number of all n-bits solutions: res = one[n - 1] + zero[n - 1].
then we subtract the solutions which is larger than num, we iterate from the MSB to LSB of num:

if bit[i] == 1
if bit[i + 1] == 0, there's no solutions in res that is larger than num, we go further into smaller
bit and subtract.
if bit[i + 1] == 1, we know in those res solutions it won't have any consecutive ones. when bit
[i + 1] == 1, in one[i + 1], the i-th bit in valid solutions must be 0, which are all smaller than
'num', we don't need to check smaller bits and subtract, so we break form the loop.
if bit[i] == 0
if bit[i + 1] == 1, there's no solutions in res that is larger than num, we go further into smaller
bit and subtract.
if bit[i + 1] == 0, we know zero[i + 1] includes solutions of i-th == 0 (00***) and i-th bit == 1 
(01***), we know the i-th bit of num is 0, so we need to subtract all the 01*** solutions because it
is larger than num. Therefore, one[i] is subtracted from res.
    int findIntegers(int num) {
        vector<int> bits;
        for (; num > 0; num >>= 1)
            bits.push_back(num & 1);
        int n = bits.size();
        
        vector<int> one(n, 0), zero(n, 0);
        one[0] = zero[0] = 1;
        for (int i = 1; i < n; i++) {
            one[i] = zero[i - 1];
            zero[i] = zero[i - 1] + one[i - 1];
        }
        
        int res = zero[n - 1] + one[n - 1];
        for (int i = n - 2; i >= 0; i--)
            if (bits[i] == 0 && bits[i + 1] == 0)
                res -= one[i];
            else if (bits[i] == 1 && bits[i + 1] == 1)
                break;
        return res;
    }

*/