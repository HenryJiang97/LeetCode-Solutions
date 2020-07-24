class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int MIN = INT_MAX;
        unordered_set<int> set;
        for (int i = 0; i < arr.size(); i++) {
            unordered_set<int> temp;
            for (int s : set) {
                MIN = min(MIN, abs((s & arr[i]) - target));
                temp.insert(s & arr[i]);
            }
            temp.insert(arr[i]);
            MIN = min(MIN, abs(arr[i] - target));
            set = temp;
        }
        return MIN;
    }
};