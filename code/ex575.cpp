class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> set;
        for (int candy : candies)    set.insert(candy);
        int n1 = set.size(), n2 = candies.size() / 2;
        return min(n1, n2);
    }
};