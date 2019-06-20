// Priority Queue / Two pointers
// O(nlogm);    n => amount of total numbers; m => Amount of numbers being added to the heap

struct cmp {bool operator()(pair<int, int> p1, pair<int, int> p2)    {return p1.first > p2.first;}};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int pointers[n] = {0};
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int MAX = INT_MIN, MIN = INT_MAX;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i][0], i));
            MAX = max(MAX, nums[i][0]);    MIN = min(MIN, nums[i][0]);
        }
        int min_gap = MAX - MIN;
        int start = MIN, end = MAX;

        // Traverse the array
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            // Move the pointer forward if possible, else break.
            if (pointers[out.second] + 1 >= nums[out.second].size())    break;
            pointers[out.second]++;
            // Push new number to the queue
            int new_num = nums[out.second][pointers[out.second]];
            pq.push(make_pair(new_num, out.second));
            // Update MIN and MAX value
            if (new_num > MAX)    MAX = new_num;
            MIN = pq.top().first;
            // Update start and end
            if (MAX - MIN < min_gap) {
                start = MIN;    end = MAX;
                min_gap = end - start;
            }
        }

        return {start, end};
    }
};