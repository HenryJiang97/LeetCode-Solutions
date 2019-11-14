// Trie

class StreamChecker {
    public Trie trie;
    public StringBuilder querysb = new StringBuilder();

    public StreamChecker(String[] words) {
        trie = new Trie();
        for (String word : words) {
            StringBuilder sb = new StringBuilder(word);
            sb.reverse();
            trie.insert(sb.toString());
        }
    }
    
    public boolean query(char letter) {
        querysb.append(letter);
        return check();
    }
    
    public boolean check() {
        trieNode p = trie.root;
        
        // Search reverse prefix of the query word in the trie tree
        for (int i = querysb.length() - 1; i >= 0; i--) {
            char c = querysb.charAt(i);
            if (p.children[c - 'a'] == null)    return false;
            if (p.children[c - 'a'].ifEnd)    return true;
            p = p.children[c - 'a'];
        }
        
        return false;
    }
}


// Define trieNode data structure
class trieNode {
    char val;
    trieNode[] children;
    boolean ifEnd;
    
    // Init
    public trieNode(char _val) {
        val = _val;
        children = new trieNode[26];
        ifEnd = false;
    }
}

// Trie data structure
class Trie {
    trieNode root;
    
    /** Initialize your data structure here. */
    public Trie() {
        root = new trieNode(' ');
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        trieNode p = root;
        
        for (int i = 0; i < word.length(); i++) {
            if (p.children[word.charAt(i) - 'a'] == null) {
                p.children[word.charAt(i) - 'a'] = new trieNode(word.charAt(i));
                p = p.children[word.charAt(i) - 'a'];
            } else {
                p = p.children[word.charAt(i) - 'a'];
            }
        }
        
        p.ifEnd = true;
    }
    
    /** Direct to the end of the string in the trie tree*/
    public trieNode direct(String word) {
        trieNode p = root;
        
        for (int i = 0; i < word.length(); i++) {
            if (p.children[word.charAt(i) - 'a'] != null)
                p = p.children[word.charAt(i) - 'a'];
            else    return null;
        }
        
        return p;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        trieNode p = direct(word);
        
        if (p != null && p.ifEnd == true)    return true;
        else    return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        trieNode p = direct(prefix);
        
        if (p != null)    return true;
        else    return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */