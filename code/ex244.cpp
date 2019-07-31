class WordDistance {
    unordered_map<string, vector<int>> map;    
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            vector<int> temp = map.find(words[i]) != map.end() ? map[words[i]] : vector<int>();
            temp.push_back(i);
            map[words[i]] = temp;
        }
    }
    
    int shortest(string word1, string word2) {
        auto arr1 = map[word1];
        auto arr2 = map[word2];
        
        int p1 = 0, p2 = 0, MIN = INT_MAX;
        while (p1 < arr1.size() && p2 < arr2.size()) {
            if (arr1[p1] < arr2[p2]) {
                MIN = min(MIN, arr2[p2] - arr1[p1]);
                p1++;
            } else {
                MIN = min(MIN, arr1[p1] - arr2[p2]);
                p2++;
            }
        }
        
        return MIN;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */