// Dual binary search

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
        
        int diff = abs(prefix.back() - target), res = arr.back();
        int lo = 0, hi = 1e5;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = getSum(arr, prefix, mid, target);
            if (abs(sum - target) < diff) {
                diff = abs(sum - target);
                res = mid;
            }
            else if (abs(sum - target) == diff)    res = min(res, mid);
            if (sum < target)    lo = mid + 1;
            else    hi = mid;
        }
        
        return res;
    }
    
private:
    int getSum(vector<int>& arr, vector<int>& prefix, int val, int target) {
        int n = arr.size();
        if (val >= arr.back())    return prefix.back();
        else if (val < arr.front())    return val * n;
        
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < val)    lo = mid + 1;
            else    hi = mid;
        }
        
        return prefix[hi] + (n - hi) * val;
    }
};