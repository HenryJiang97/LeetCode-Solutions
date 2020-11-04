class Solution {
    int mod = 1e9 + 7;
    int n1, n2;
    unordered_map<int, int> map1, map2;
    vector<int> arr1, arr2;
    vector<vector<long>> memo;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();    n2 = nums2.size();
        arr1 = nums1;    arr2 = nums2;
        for (int i = 0; i < n1; i++)    map1[nums1[i]] = i;
        for (int i = 0; i < n2; i++)    map2[nums2[i]] = i;
        memo = vector<vector<long>>(2, vector<long>(max(n1, n2)));
        return (int)(max(backtracking(0, 0), backtracking(1, 0)) % mod);
    }
    
private:
    long backtracking(int arr, int p) {
        if (arr == 0 && p >= n1 || arr == 1 && p >= n2)    return 0;
        if (memo[arr][p] != 0)    return memo[arr][p];
        
        long MAX = 0;
        if (arr == 0) {    // arr1
            MAX = max(MAX, backtracking(arr, p + 1) + arr1[p]);
            if (map2.count(arr1[p]) > 0) {
                MAX = max(MAX, backtracking(1, map2[arr1[p]] + 1) + arr1[p]);
            }
        }
        else {    // arr2
            MAX = max(MAX, backtracking(arr, p + 1) + arr2[p]);
            if (map1.count(arr2[p]) > 0) {
                MAX = max(MAX, backtracking(0, map1[arr2[p]] + 1) + arr2[p]);
            }
        }
            
        memo[arr][p] = MAX;
        return MAX;
    }
};