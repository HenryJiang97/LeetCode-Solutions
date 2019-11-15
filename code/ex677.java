class MapSum {
    public Set<String> exist;
    public TrieNode root;

    /** Initialize your data structure here. */
    public MapSum() {
        exist = new HashSet<>();
        root = new TrieNode();
    }
    
    public void insert(String key, int val) {
        boolean ifExist = exist.contains(key);
        exist.add(key);
        TrieNode p = root;
        for (int i = 0; i < key.length(); ++i) {
            char c = key.charAt(i);
            if (p.children[c - 'a'] == null) {
                p.children[c - 'a'] = new TrieNode();
            }
            if (ifExist)    p.children[c - 'a'].sum = val;
            else    p.children[c - 'a'].sum += val;
            p = p.children[c - 'a'];
        }
    }
    
    public int sum(String prefix) {
        TrieNode p = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            if (p.children[c - 'a'] == null)
                return 0;
            p = p.children[c - 'a'];
        }
        return p.sum;
    }
}

class TrieNode {
    public TrieNode[] children = new TrieNode[26];
    public int sum = 0;
    public TrieNode() {}
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */