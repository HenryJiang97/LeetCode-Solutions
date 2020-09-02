class Solution {
    vector<int> original;
    int n;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = original;
        for (int i = 0; i < n; i++) {
            int idx = rand() % n;
            swap(res[i], res[idx]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */