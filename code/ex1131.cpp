class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> v1(n), v2(n), v3(n), v4(n);
        for (int i = 0; i < n; i++) {
            v1[i] = arr1[i] + arr2[i] + i;
            v2[i] = arr1[i] + arr2[i] - i;
            v3[i] = arr1[i] - arr2[i] + i;
            v4[i] = arr1[i] - arr2[i] - i;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());
        
        return max(max(v1[n - 1] - v1[0], v2[n - 1] - v2[0]), max(v3[n - 1] - v3[0], v4[n - 1] - v4[0]));
    }
};