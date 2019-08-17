class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        
        string s = "";
        bool inAComment = false;
        for (auto line : source) {
            for (int i = 0; i < line.length(); i++) {
                // Dismiss a line starting with "//" and not in a comment block
                if (!inAComment && line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/')
                    break;
                
                if (inAComment) {    // In a comment block
                    if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                        inAComment = false;
                        i++;
                    }
                }
                else {    // Not in a comment block
                    if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                        inAComment = true;
                        i++;
                    } else {
                        s += line[i];
                    }
                }       
            }
            
            if (!inAComment && s != "") {
                res.push_back(s);
                s = "";
            }
        }
        
        return res;
    }
};