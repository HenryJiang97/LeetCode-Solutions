// Time complexity: O((right - left + 1) * len(n)) = O(n)

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++)
            if (selfDiv(i))    res.push_back(i);
        return res;
    }
    
private:
    bool selfDiv(int num) {
        int n = num;
        while (n > 0) {
            int d = n % 10;
            if (d == 0 || num % d != 0)    return 0;
            n /= 10;
        }
        return 1;
    }
};