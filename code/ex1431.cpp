class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), MAX = 0;
        for (int candy : candies)    MAX = max(MAX, candy);
        vector<bool> res;
        for (int candy : candies)    res.push_back(candy + extraCandies >= MAX);
        return res;
    }
};