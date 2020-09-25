class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return to_string(a) + to_string(b) > to_string(b) + to_string(a);});
        string res = "";
        for (int num : nums)    res += to_string(num);
        // Remove front zeros
        int i;
        for (i = 0; i < nums.size() - 1 && res[i] == '0'; i++) {}
        return res.substr(i);
    }
};