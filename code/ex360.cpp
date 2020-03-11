class Solution {
    int a, b, c;
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        this->a = a;    this->b = b;    this->c = c;
        int n = nums.size();
        
        // a == 0
        if (a == 0) {
            vector<int> res;
            if (b > 0) {
                for (int i = 0; i < n; ++i)
                    res.push_back(calculate(nums[i]));
            }
            else {
                for (int i = n - 1; i >= 0; --i)
                    res.push_back(calculate(nums[i]));
            }
            return res;
        }
        
        // a != 0
        double pivot = -(double)b / (2 * a);
        
        // Binary search in the nums array to find the pivot
        int lo = 0, hi = n - 1, p = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= pivot) {
                if (mid - 1 < 0 || nums[mid - 1] < pivot) {
                    p = mid;
                    break;
                }
                hi = mid - 1;
            }
            else    lo = mid + 1;
        }
        
        // Get res
        vector<int> res;
        int left = p - 1, right = p;
        while (left >= 0 || right < n) {
            if (left < 0)    res.push_back(calculate(nums[right++]));
            else if (right >= n)    res.push_back(calculate(nums[left--]));
            else {
                int leftval = calculate(nums[left]), rightval = calculate(nums[right]);
                if (a > 0) {
                    if (leftval >= rightval)    res.push_back(calculate(nums[right++]));
                    else    res.push_back(calculate(nums[left--]));
                } else {
                    if (leftval >= rightval)    res.push_back(calculate(nums[left--]));
                    else    res.push_back(calculate(nums[right++]));
                }
            }
        }
        if (a < 0)    reverse(res.begin(), res.end());
        
        return res;
    }
    
private:
    int calculate(int x) {
        return a * x * x + b * x + c;
    }
};