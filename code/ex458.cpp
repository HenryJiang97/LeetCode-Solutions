// Math, (T+1)^x >= N; N:buckets, T: Total tests can be performed, x: num of pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie;
        int x = 0, res = 1;
        while (res < buckets) {
            res *= (T + 1);
            x++;
        }
        return x;
    }
};