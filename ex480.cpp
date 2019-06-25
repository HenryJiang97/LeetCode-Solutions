class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        
        multiset<int> set;
        for (int i = 0; i < k; i++)    set.insert(nums[i]);
        for (int i = k - 1; i < n; i++) {
            res.push_back(getMedian(set));
            remove(set, nums[i - k + 1]);
            if (i + 1 < n)    set.insert(nums[i + 1]);
        }
        
        return res;
    }

private:
    double getMedian(multiset<int>& set) {
        auto it = set.begin();
        int size = set.size();
        double m = 0.0;
        if (size % 2 == 1) {
            it = next(it, (size - 1) / 2);
            m = (double)(*it);
        } else {
            it = next(it, size / 2 - 1);
            m += (double)(*it);    it = next(it);    m += (double)(*it);
            m /= 2;
        }
        return m;
    }
    
    void remove(multiset<int>& set, int remove) {
        auto find = set.find(remove);
        set.erase(find);
    }
};