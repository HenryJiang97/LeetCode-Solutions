class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        unordered_map<int, int> map;
        for (int t : time) {
            cnt += map[t % 60];
            map[(60 - t % 60) % 60]++;
        }
        return cnt;
    }
};