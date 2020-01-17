class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, new Comparator<String>() {
            public int compare(String a, String b) {
                return b.length() - a.length();
            }
        });
        
        // Insert to trie
        int cnt = 0;
        TrieNode tn = new TrieNode();
        for (String word : words) {
            TrieNode p = tn;
            for (int i = word.length() - 1; i >= 0; i--) {
                char c = word.charAt(i);
                if (i == 0 && (p.children[c - 'a'] == null))    cnt += word.length() + 1;
                if (p.children[c - 'a'] == null) {
                    p.children[c - 'a'] = new TrieNode();
                } 
                p = p.children[c - 'a'];
            }
        }
        
        return cnt;
    }
}

class TrieNode {
    TrieNode[] children;
    TrieNode() {
        children = new TrieNode[26];
    }
}