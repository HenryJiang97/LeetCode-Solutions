// Fast slow pointers

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)    return false;
        for (int i = 0; i < n; i++) {
            if (helper(nums, i))    return true;
        }
        return false;
    }
    
    // Detect cycle start from index s
    bool helper(vector<int>& nums, int s) {
        int n = nums.size();

        // Fast slow pointer to find 
        int pFast = s, pSlow = s, cnt = 0;
        while (cnt == 0 || (pFast != pSlow && cnt < 100)) {
            // Move pSlow
            if (nums[pSlow] == 0)    return false;
            else if (nums[pSlow] > 0)    pSlow = (pSlow + nums[pSlow]) % n;
            else {
                pSlow = pSlow + nums[pSlow];
                while (pSlow < 0)    pSlow += n;
            }

            // Move pFast
            for (int i = 0; i < 2; i++) {
                if (nums[pFast] == 0)    return false;
                else if (nums[pFast] > 0)    pFast = (pFast + nums[pFast]) % n;
                else {
                    pFast = pFast + nums[pFast];
                    while (pFast < 0)    pFast += n;
                }
            }
            cnt++;
        }
        if (pFast != pSlow)    return false;
        
        // Judge the loop
        int len = 0, p = pSlow, sign = nums[pSlow] > 0 ? 1 : 0;
        while (len == 0 || p != pSlow) {
            int dir = nums[p] > 0 ? 1 : 0;
            if (dir != sign)    return false;
            
            // Move pointer p
            if (nums[p] == 0)    return false;
            else if (nums[p] > 0)    p = (p + nums[p]) % n;
            else {
                p = p + nums[p];
                while (p < 0)    p += n;
            }
            len++;
        }
        if (len == 1)    return false;
        
        return true;
    }
};