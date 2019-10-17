class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        for (int i = 0; i < 26; i++)    parent[i] = i;
        
        for (auto& equ : equations) {
            if (equ[1] == '=' && equ[2] == '=') {
                uni(parent, equ[0] - 'a', equ[3] - 'a');
            }
        }
        
        for (auto& equ : equations) {
            if (equ[1] == '!' && equ[2] == '=') {
                if (find(parent, equ[0] - 'a') == find(parent, equ[3] - 'a'))
                    return 0;
            }
        }
        
        return 1;
    }
    
private:
    int find(vector<int>& parent, int p) {
        if (parent[p] != p)
            parent[p] = find(parent, parent[p]);
        return parent[p];
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)
            parent[rb] = ra;
        else
            parent[ra] = rb;
    }
};