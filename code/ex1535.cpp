class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix{arr[0]};
        for (int i = 1; i < n; i++)    prefix.push_back(max(prefix.back(), arr[i]));
        
        for (int i = 0; i < n; i++) {
            if ((i == 0 || prefix[i - 1] < arr[i]) && prefix[min(i == 0 ? i + k : i + k - 1, n - 1)] == prefix[i])
                return arr[i];
        }
        
        return -1;
    }
};