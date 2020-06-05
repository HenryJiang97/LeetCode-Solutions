// Union Find

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return 0;
        
        unordered_set<int> set;
        for (int num : nums)    set.insert(num);
        
        // Union Find
        unordered_map<int, int> parent;
        for (int num : set)    parent[num] = num;
        for (int num : set) {
            if (set.count(num + 1) > 0)    uni(parent, num, num + 1);
        }
        
        // Group
        unordered_map<int, pair<int, int>> group;    // {root, {min, max}}
        for (int num : set) {
            int root = find(parent, num);
            int minEle = group.count(root) > 0 ? group[root].first : INT_MAX;
            int maxEle = group.count(root) > 0 ? group[root].second : INT_MIN;
            minEle = min(minEle, num);
            maxEle = max(maxEle, num);
            group[root] = {minEle, maxEle};
        }
        
        // Get result
        int MAX = 1;
        for (auto& [k, v] : group)
            MAX = max(MAX, v.second - v.first + 1);
        
        return MAX;
    }
    
private:
    void uni(unordered_map<int, int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    int find(unordered_map<int, int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
};