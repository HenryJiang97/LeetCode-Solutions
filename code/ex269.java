// Topological ordering

class Solution {
    public int n = 0;
    
    public String alienOrder(String[] words) {
        n = words.length;
        
        // Build dictionary
        Map<Character, Set<Character>> dict = buildDict(words);
        
        // Topological ordering
        String res = "";
        
        // Get the indegree of each node
        char[] indegree = new char[26];
        for (Character key : dict.keySet()) {
            for (Character v : dict.get(key)) {
                indegree[v - 'a']++;
            }
        }
        
        // Ordering
        Queue<Character> queue = new LinkedList<>();
        for (Map.Entry<Character, Set<Character>> entry : dict.entrySet()) {
            if (indegree[entry.getKey() - 'a'] == 0)
                queue.offer(entry.getKey());
        }
        
        while (!queue.isEmpty()) {
            char out = queue.poll();
            res += out;
            
            for (char c : dict.get(out)) {
                if (--indegree[c - 'a'] == 0)
                    queue.offer(c);
            }
        }
        
        return res.length() != dict.size() ? "" : res;
    }
    
    private Map<Character, Set<Character>> buildDict(String[] words) {
        Map<Character, Set<Character>> dict = new HashMap<>();
        
        for (int i = 0; i < n - 1; i++) {
            String word1 = words[i], word2 = words[i + 1];
            for (int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
                char c1 = word1.charAt(j), c2 = word2.charAt(j);
                if (c1 != c2) {
                    Set<Character> set = dict.getOrDefault(c1, new HashSet<Character>());
                    set.add(c2);
                    dict.put(c1, set);
                    break;
                }
            }
        }
        
        // Add the rest characters with no next node
        for (int i = 0; i < n; i++) {
            for (char c : words[i].toCharArray()) {
                if (!dict.containsKey(c))    dict.put(c, new HashSet<Character>());
            }
        }
        
        return dict;
    }
}