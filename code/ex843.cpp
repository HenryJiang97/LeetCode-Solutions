/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while (1) {
            int n = wordlist.size();
            int ra = rand() % n;
            
            string word = wordlist[ra];
            int sameDigits = master.guess(word);
            if (sameDigits == 6)    return;
            
            // Eliminate words in the list which are not haveing the number of same digts as word
            vector<string> newList;
            for (string w : wordlist) {
                if (getMatches(w, word) == sameDigits)    newList.push_back(w);
            }
            
            wordlist = newList;
        }
    }
    
private:
    int getMatches(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (s1[i] == s2[i])
                cnt++;
        }
        return cnt;
    }
};