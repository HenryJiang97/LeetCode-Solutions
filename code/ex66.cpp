class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int val = digits[i] + carry;
            digits[i] = val % 10;
            carry = val / 10;
        }
        if (carry == 1)    digits.insert(digits.begin(), 1);
        
        return digits;
    }
};