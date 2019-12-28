class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        auto greyCode = generateGreyCode(n);
        int p = 0;
        while (p < greyCode.size()) {
            if (greyCode[p] == start)
                break;
            p++;
        }
        
        // Rotate the array
        vector<int> res;
        for (int i = p; i < greyCode.size(); i++)
            res.push_back(greyCode[i]);
        for (int i = 0; i < p; i++)
            res.push_back(greyCode[i]);
        return res;
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