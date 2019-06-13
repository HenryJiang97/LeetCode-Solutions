// Trie, DFS

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
}

class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Trie trie = new Trie();
        
        for (String s : words)
            trie.insert(s);
        
        List<String> res = new ArrayList<>();
        for (String s : words) {
            for (int i = 0; i < s.length(); i++) {
                if (trie.search(s.substring(0, i + 1)) && dfs(s, trie, i + 1)) {
                    res.add(s);
                    break;
                }
            }   
        }
 
        return res;
    }
    
    private boolean dfs(String s, Trie trie, int start) {
        boolean res = false;
        for (int i = start; i < s.length(); i++) {
            if (trie.search(s.substring(start, i + 1)) && i + 1 == s.length())
                res = true;
            else if (trie.search(s.substring(start, i + 1)))    
                res = dfs(s, trie, i + 1);
            if (res)    return true;
        }
        return res;
    }
}