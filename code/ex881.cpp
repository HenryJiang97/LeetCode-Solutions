class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        
        int lo = 0, hi = n - 1, cnt = 0;
        while (lo <= hi) {
            if (people[lo] + people[hi] <= limit) {
                cnt++;
                lo++;    hi--;
            }
            else if (people[hi] <= limit) {
                cnt++;
                hi--;
            }
            else if (people[lo] <= limit) {
                cnt++;
                lo++;
            }
        }
        
        return cnt;
    }
};