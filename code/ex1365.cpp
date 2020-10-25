struct BIT {
    vector<int> prefix;
    
    BIT(int n) {
        prefix.resize(n + 1);
    }
    
    void update(int i, int delta) {
        i++;
        while (i < prefix.size()) {
            prefix[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += prefix[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        BIT* bit = new BIT(101);
        for (int n : nums) {
            bit->update(n, 1);
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(bit->query(nums[i] - 1));
        }
        
        return res;
    }
};