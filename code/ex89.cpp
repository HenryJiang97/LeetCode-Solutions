class Solution {
    int val = 0;
public:
    vector<int> grayCode(int n) {
        return generateGreyCode(n);
    }
    
private:
    vector<int> generateGreyCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            int size = res.size();
            for (int j = size - 1; j >= 0; j--) {
                res.push_back(res[j] + (1 << i));
            }
        }
        return res;
    }
};