class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // Get array of changes
        vector<int> changes(length + 1);
        for (auto& update : updates) {
            changes[update[0]] += update[2];
            changes[update[1] + 1] -= update[2];
        }
        
        // Get results
        int cur = 0;
        for (int i = 0; i < length; i++) {
            cur += changes[i];
            changes[i] = cur;
        }
        changes.resize(length);
        return changes;
    }
};