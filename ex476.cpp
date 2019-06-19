class Solution {
public:
    int findComplement(int num) {  
        vector<int> bit;
        while (num > 0) {
            bit.push_back(num & 1);
            num = num >> 1;
        }
        
        int new_num = 0;
        while (!bit.empty()) {
            new_num = new_num << 1;
            if (bit.back() == 0)    new_num += 1;
            bit.pop_back();
        }
        
        return new_num;
    }
};