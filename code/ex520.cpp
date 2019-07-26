class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n <= 1)    return true;
        
        if (ifLowercase(word[0])) {    // Case 2
            for (int i = 1; i < n; i++)
                if (!ifLowercase(word[i]))    return false;
            
        } else {
            if (ifLowercase(word[1])) {    // Case 3
                for (int i = 2; i < n; i++)
                    if (!ifLowercase(word[i]))    return false;
                    
            } else {    // Case 1
                for (int i = 2; i < n; i++)
                    if (ifLowercase(word[i]))    return false;
            }
        }
        
        return true;
    }
    
private:
    bool ifLowercase(char c) {
        return (c >= 'a' && c <= 'z') ? true : false;
    }
};