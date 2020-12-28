struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        memset(children, NULL, sizeof(children));
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        unordered_set<int> set(nums.begin(), nums.end());
        nums = vector<int>(set.begin(), set.end());
        sort(nums.begin(), nums.end());
        
        vector<int> res(n);
        TrieNode* root = new TrieNode();
        int i = 0;
        for (auto& query : queries) {
            int x = query[0], m = query[1], idx = query[2];
            
            // Insert new valid nums to trie
            while (i < nums.size() && nums[i] <= m) {
                string s = std::bitset<32>(nums[i]).to_string();
                TrieNode* p = root;
                for (char c : s) {
                    if (p->children[c - '0'] == NULL) {
                        p->children[c - '0'] = new TrieNode();
                    }
                    p = p->children[c - '0'];
                }
                i++;
            }
            
            // Search in the trie tree to find out the max XOR
            int XOR = 0;
            string s = std::bitset<32>(x).to_string();
            TrieNode* p = root;
            for (char c : s) {
                int cur = c - '0';
                if (p == NULL) {
                    res[idx] = -1;
                    break;
                }
                if (p->children[1 - cur] != NULL) {
                    p = p->children[1 - cur];
                    XOR = (XOR << 1) + 1;
                } else {
                    p = p->children[cur];
                    XOR = (XOR << 1) + 0;
                }
            }
            
            res[idx] = res[idx] == 0 ? XOR : res[idx];
        }
        
        return res;
    }
};