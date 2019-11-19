// x + (x + 1) + (x + 2) + ... + (x + m - 1) = N
// => x = (2N - m ^ 2) / 2m + 1/2,  m < sqrt(2 * N)

class Solution {
    public int consecutiveNumbersSum(int N) {
        int cnt = 0;
        for (int m = 1; m < Math.sqrt(2 * N); m++) {
            double x = (double)(2 * N - m * m + m) / (2 * m);
            if (Math.floor(x) == x && x > 0)    cnt++;
        }
        return cnt;
    }
}