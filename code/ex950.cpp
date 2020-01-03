class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end(), greater<int>());
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (!que.empty()) {
                int frt = que.front();    que.pop();
                que.push(frt);
            }
            que.push(deck[i]);
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.front());
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};