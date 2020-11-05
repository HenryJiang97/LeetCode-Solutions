class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        long res = 0, sum1 = 0, sum2 = 0;
        while (p1 < n1 || p2 < n2) {
            if (p1 == n1) {
                sum2 += nums2[p2++];
            } else if (p2 == n2) {
                sum1 += nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                sum1 += nums1[p1++];
            } else if (nums2[p2] < nums1[p1]) {
                sum2 += nums2[p2++];
            } else if (nums1[p1] == nums2[p2]) {
                sum1 += nums1[p1];
                sum2 += nums2[p2];
                res += max(sum1, sum2);
                sum1 = sum2 = 0;
                p1++;    p2++;
            }
            res %= mod;
        }
        return (int)((res + max(sum1, sum2)) % mod);
        
    }
};