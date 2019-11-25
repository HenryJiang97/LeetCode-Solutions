const int mod = 1e9 + 7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum = 0;
        for (int a : arr)    sum = (sum + a) % mod;
        
        int res = 0;
        
        // If the sum of one repete is positive, accumulate the middle part of the array
        if (sum > 0)
            res += (int)((long)(k - 2) * sum % mod);
        
        // Find the max subarray of 2 * arr, serve as the head and tail of the result subarray
        vector<int> array(arr.begin(), arr.end());
        for (int a : arr)    array.push_back(a);

        return (res + maxSubarray(array)) % mod;
    }
    
private:
    int maxSubarray(vector<int>& array) {
        int MAX = 0;
        int sum = 0;
        for (int i = 0; i < array.size(); i++) {
            if (sum + array[i] < array[i]) {
                sum = array[i];
            } else {
            	sum = (sum + array[i]) % mod;
            }
            MAX = max(MAX, sum);
        }
        return MAX;
    }
};