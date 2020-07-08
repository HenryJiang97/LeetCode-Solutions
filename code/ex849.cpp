class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), MAX = 0;
        
        // Find the first 1 and last 1
        int lo = 0, hi = n - 1;
        while (lo <= hi && seats[lo] == 0)    lo++;
        while (hi >= lo && seats[hi] == 0)    hi--;
        
        if (lo > MAX)    MAX = lo;
        if (n - 1 - hi > MAX)    MAX = n - 1 - hi;
        
        int prev = lo;
        for (int lo = 0; lo <= hi; lo++) {
            if (seats[lo] == 0)    continue;
            if ((lo - prev) / 2 > MAX)    MAX = (lo - prev) / 2;
            prev = lo;
        }
        
        return MAX;
    }
};