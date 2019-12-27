class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> score(n, 1);
        for (int i = 1; i < n; i++)    // Compare each rating with the one before, if larger, give it a score 1 greater than before
            if (ratings[i] > ratings[i - 1])
                score[i] = score[i - 1] + 1;
        for (int i = n - 2; i >= 0; --i)    // Compare each rating with one after, if larger, update the score to meet the new requirement
            if (ratings[i] > ratings[i + 1])
                score[i] = max(score[i], score[i + 1] + 1);
        return accumulate(score.begin(), score.end(), 0);
    }
};