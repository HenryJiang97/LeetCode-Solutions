class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        arr.insert(arr.begin(), 0);
        arr.push_back(2001);
        for (int i = 1; i < arr.size(); i++) {
            int gap = arr[i] - arr[i - 1] - 1;
            if (gap >= k)    return arr[i - 1] + k;
            else    k -= gap;
        }
        return 0;
    }
};