class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        
        for (string& email : emails) {
            string str = "";
            bool hasPlus = false;
            for (int i = 0; i < email.length(); i++) {
                if (email[i] == '@') {
                    str += email.substr(i);
                    break;
                } else if (email[i] == '.')    continue;
                else if (email[i] == '+')    hasPlus = true;
                else if (!hasPlus)    str += email[i];
            }
            s.insert(str);
        }
        
        return s.size();
    }
};