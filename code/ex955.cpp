class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        
        int cnt = 0;
        vector<string> cur(n, "");
        for (int i = 0; i < A[0].length(); i++) {    // O(w * n)
            vector<string> temp = cur;
            for (int j = 0; j < n; j++) {
                temp[j] += A[j][i];
            }
            if (isSorted(temp)) {
                cur = temp;
            } else {
                cnt++;
            }
        }
        
        return cnt;
    }
    
private:
    bool isSorted(vector<string>& arr) {    // O(n)
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i])    return 0;
        }
        return 1;
    }
};