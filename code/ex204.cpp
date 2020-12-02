class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isPrime(n, 1);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
                for (int j = 2; i * j < n; j++) {
                    isPrime[i * j] = 0;
                }
            }
        }
        return cnt;
    }
};