class Solution {
    struct cmp {
        bool operator()(string a, string b) {
            return b + a < a + b;
        }
    };
    
public:
    string largestNumber(vector<int>& nums) {
        vector<string> candidates;
        for (int n : nums)    candidates.push_back(to_string(n));
        sort(candidates.begin(), candidates.end(), cmp());
        string res = "";
        for (string can : candidates)    res += can;
        // Remove extra leading zeros
        int p = 0;
        while (p < res.length() - 1 && res[p] == '0')    p++;
        return res.substr(p);
    }
};