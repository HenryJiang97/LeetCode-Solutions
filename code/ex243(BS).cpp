class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < n; i++)    map[words[i]].push_back(i);
        
        // Binary search for the closest word2 of each word1
        int MIN = n;
        vector<int> idx1 = map[word1], idx2 = map[word2];
        for (int a : idx1) {
            MIN = min(MIN, bs(idx2, a));
        }
        return MIN;
    }
    
private:
    int bs(vector<int>& idx2, int target) {
        int n = idx2.size();
        int lo = 0, hi = n - 1;
        int MIN = min(abs(target - idx2[lo]), abs(target - idx2[hi]));
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (idx2[mid] < target) {
                MIN = min(MIN, target - idx2[mid]);
                lo = mid + 1;
            }
            else {
                MIN = min(MIN, idx2[mid] - target);
                hi = mid;
            }
        }
        return MIN;
    }
};