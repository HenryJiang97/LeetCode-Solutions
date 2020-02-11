class Solution {
    public boolean equationsPossible(String[] equations) {
        int[] parent = new int[26];
        for (int i = 0; i < 26; i++)    parent[i] = i;
        
        for (String equ : equations)
            if (equ.charAt(1) == '=')
                uni(parent, equ.charAt(0) - 'a', equ.charAt(3) - 'a');

        for (String equ : equations)
            if (equ.charAt(1) == '!')
                if (find(parent, equ.charAt(0) - 'a') == find(parent, equ.charAt(3) - 'a'))
                    return false;
        
        return true;
    }
    
    private void uni(int[] parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    private int find(int[] parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
}