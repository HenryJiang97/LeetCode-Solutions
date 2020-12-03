class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        
        multimap<int, int> mmap;
        vector<int> idx(n, 1);    // idx for each array
        for (int i = 0; i < n; i++)    mmap.insert({nums[i][0], i});
        
        vector<int> range{(*mmap.begin()).first, (*mmap.rbegin()).first};
        while (1) {
            int i = (*mmap.begin()).second, val = (*mmap.begin()).first;
            if (idx[i] >= nums[i].size())    break;
            
            mmap.erase(mmap.begin());
            mmap.insert({nums[i][idx[i]++], i});
            
            if ((*mmap.rbegin()).first - (*mmap.begin()).first < range[1] - range[0]) {
                range = {(*mmap.begin()).first, (*mmap.rbegin()).first};
            }
        }
        
        return range;
    }
};