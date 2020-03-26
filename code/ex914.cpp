class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int d : deck)    cnt[d]++;
        int X = -1;
        for (auto& [key, value] : cnt) {
            if (X == -1)    X = value;
            else    X = GCD(X, value);
        }
        return X >= 2;
    }
    
private:
    int GCD(int a, int b) {
        if (b == 0)    return a;
        return GCD(b, a % b);
    }
};