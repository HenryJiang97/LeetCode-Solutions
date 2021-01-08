class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while (i1 < n1 && i2 < n2) {
            if (j1 >= word1[i1].length())    {i1++;    j1 = 0;}
            if (j2 >= word2[i2].length())    {i2++;    j2 = 0;}
            if (i1 >= n1 || i2 >= n2)    break;
            if (word1[i1][j1] != word2[i2][j2])    return 0;
            j1++;    j2++;
        }
        
        return i1 == n1 && i2 == n2;
    }
};