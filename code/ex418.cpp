class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string sen = buildSentence(sentence);
        int n = sen.length();
        
        int i = 0;
        for (int r = 0; r < rows; r++) {
            i += cols;
            if (sen[i % n] == ' ') {
                i++;
            } else {
                // Trace back to last word
                while (i >= 0 && sen[i % n] != ' ') {
                    i--;
                }
                i++;
            }
        }
        
        return i / n;
    }

private:
    string buildSentence(vector<string>& sentence) {
        string s = "";
        for (string sen : sentence)
            s += sen + " ";
        return s;
    }
};