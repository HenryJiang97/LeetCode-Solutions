class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0)    return 0;
        
        map<int, int> cnt;
        for (int h : hand)    cnt[h]++;
        
        while (!cnt.empty()) {
            int base = (*cnt.begin()).first;
            if (--cnt[base] == 0)    cnt.erase(base);
            for (int i = 1; i < W; i++) {
                if (cnt.count(base + i) == 0)    return 0;
                if (--cnt[base + i] == 0)    cnt.erase(base + i);
            }
        }
        
        return 1;
    }
};