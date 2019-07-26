import java.util.*;

class Solution {
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

    // Define Trie Tree
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

    
    private HashSet<String> result = new HashSet<>();
    
    public void dfs(Trie obj, char[][] board, int[][] visited, String word, int i, int j) {
        word += Character.toString(board[i][j]);
        
        // If the word is in the trie tree, found
        if (obj.search(word))    result.add(word);
        // If the preflix is not in the trie tree, return
        if (!obj.startsWith(word))    return;
        
        visited[i][j] = 1;
        
        // Go to four directions if available
        if (i + 1 < board.length && visited[i + 1][j] == 0)
            dfs(obj, board, visited, word, i + 1, j);
        if (j + 1 < board[0].length && visited[i][j + 1] == 0)
            dfs(obj, board, visited, word, i, j + 1);
        if (i - 1 >= 0 && visited[i - 1][j] == 0)
            dfs(obj, board, visited, word, i - 1, j);
        if (j - 1 >= 0 && visited[i][j - 1] == 0)
            dfs(obj, board, visited, word, i, j - 1);
        
        visited[i][j] = 0;
    }
    
    
    public List<String> findWords(char[][] board, String[] words) {
        Trie obj = new Trie();
        
        // Add words to trie tree
        for (String w : words)    obj.insert(w);
        
        
        // Check if any possible word is in the trie tree
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                String word = "";
                dfs(obj, board, new int[board.length][board[0].length], word, i, j);
            }
        }

        
        return new ArrayList<String>(result);
    }
}