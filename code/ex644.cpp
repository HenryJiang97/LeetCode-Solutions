class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = (double)INT_MIN, hi = (double)INT_MAX;
        while (hi - lo > 0.00001) {
            double mid = lo + (hi - lo) / 2;
            if (check(nums, k, mid))    lo = mid;
            else    hi = mid;
        }
        return lo;
    }
    
private:
    bool check(vector<int>& nums, int k, double sum) {
        vector<double> arr;
        for (int i = 0; i < nums.size(); i++)
            arr.push_back((double)nums[i] - sum);
        
        double cur = 0.0, prev = 0.0;
        for (int i = 0; i < k; i++)    cur += arr[i];
        if (cur >= 0)    return 1;
        
        for (int i = k; i < arr.size(); i++) {
            cur += arr[i];
            prev += arr[i - k];
            if (prev < 0) {
                cur -= prev;
                prev = 0;
            }
            if (cur >= 0)    return 1;
        }
        
        return 0;
    }
};