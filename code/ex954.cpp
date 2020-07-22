class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int n = A.size();
        
        map<int, int> pos, neg;
        int zeros = 0;
        for (int a : A) {
            if (a == 0)    zeros++;
            else if (a > 0)    pos[a]++;
            else    neg[a]++;
        }
        
        // Zeros
        if (zeros % 2 != 0)    return 0;
        
        // Positive
        for (auto& [k, v] : pos) {
            if (pos.count(k * 2) == 0 || pos[k * 2] < pos[k])    return 0;
            pos[k * 2] -= v;
            if (pos[k * 2] == 0)    pos.erase(k * 2);
        }
        
        // Negative
        for (auto& [k, v] : neg) {
            if (k % 2 != 0 || neg.count(k / 2) == 0 || neg[k / 2] < neg[k])    return 0;
            neg[k / 2] -= v;
            if (neg[k / 2] == 0)    neg.erase(k / 2);
        }
        
        return 1;
    }
};