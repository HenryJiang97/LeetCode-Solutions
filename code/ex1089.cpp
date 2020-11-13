class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int p = 0, cnt = 0, zeros = 0;
        while (p < n && cnt < n) {
            zeros += arr[p] == 0 ? 1 : 0;
            cnt += arr[p++] == 0 ? 2 : 1;
        }
        p--;
        while (p >= 0) {
            if (arr[p] == 0) {
                zeros--;
                arr[p + zeros] = 0;
                if (p + zeros + 1 < n)    arr[p + zeros + 1] = 0;
            } else {
                arr[p + zeros] = arr[p];
            }
            p--;
        }
    }
};