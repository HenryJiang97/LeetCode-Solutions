struct FenwickTree{
    vector<int> arr;
    FenwickTree(int n) {arr.resize(n + 1);}
    void update(int i, int x) {
        i++;
        while (i < arr.size()) {
            arr[i] += x;
            i += (i) & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        i++;
        while (i > 0) {
            sum += arr[i];
            i -= (i) & (-i);
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        int N = 2 * (int)(1e5);
        FenwickTree* ft = new FenwickTree(N);
        
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];
            res[i] = ft->query(val + (int)(1e5) - 1);
            ft->update(val + (int)(1e5), 1);
        }

        return res;
    }
};