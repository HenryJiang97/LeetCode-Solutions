class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int cnt = 0, lo = 0, hi = n - 1;
        while (lo <= hi) {
            int l = limit - people[hi--];
            if (lo <= hi && l - people[lo] >= 0) {
                l -= people[lo++];
            }
            cnt++;
        }
        return cnt;
    }
};