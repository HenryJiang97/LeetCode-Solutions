// Trie

class WordFilter {
    public TrieNode root;
    
    public WordFilter(String[] words) {
        root = new TrieNode();
        for (int i = 0; i < words.length; i++) {
            String s = words[i];
            for (int j = 0; j <= s.length(); j++) {
                String ns = s.substring(j) + "#" + s;
                insert(ns, i);
            }
        }
    }
    
    public int f(String prefix, String suffix) {
        TrieNode p = root;
        String target = suffix + "#" + prefix;
        
        for (int i = 0; i < target.length(); i++) {
            char c = target.charAt(i);
            if (c == '#')    c = 'a' + 26;
            if (p.children[c - 'a'] == null)
                return -1;
            else
                p = p.children[c - 'a'];
        }
        return p.weight;
    }
    
    // Insert string to trie tree
    public void insert(String s, int weight) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '#')    c = 'a' + 26;
            if (p.children[c - 'a'] == null)
                p.children[c - 'a'] = new TrieNode();
            p.children[c - 'a'].weight = weight;
            p = p.children[c - 'a'];
        }
    }
}

class TrieNode {
    public TrieNode[] children = new TrieNode[27];
    public int weight = 0;
    public TrieNode() {}
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */