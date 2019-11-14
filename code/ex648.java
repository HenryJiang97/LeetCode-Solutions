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
    public String replaceWords(List<String> dict, String sentence) {
        Trie trie = new Trie();
        for (String d : dict)
            trie.insert(d);
        
        String[] words = sentence.split(" ");
        String res = "";
        for (String word : words) {
            boolean found = false;
            for (int i = 1; i < word.length(); i++) {
                String substr = word.substring(0, i);
                if (trie.search(substr)) {
                    res = res + substr + " ";
                    found = true;
                    break;
                }
            }
            if (!found)    res = res + word + " ";
        }
        
        res = res.trim();
        return res;
    }
}