class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people, candy = 1, idx = 0;
        vector<int> res(n);
        while (candies > candy) {
            res[idx++ % n] += candy;
            candies -= candy++;
        }
        res[idx % n] += candies;
        return res;
    }
};