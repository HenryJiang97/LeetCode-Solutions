// Trie + priority queue
// Time complexity:
// Init: O(n + l), n->number of sentences, l->the max length of the sentences
// Construct: O(mlog(m)), m->available candidates for hot sentences.

class TrieNode {
    public TrieNode[] children = new TrieNode[27];
    public Map<String, Integer> cnt = new HashMap<>();    // Get the hotDegree of a string
}

class si {
    public String str;
    public int hotDegree;
    public si(String str, int hotDegree) {
        this.str = str;
        this.hotDegree = hotDegree;
    }
}

class AutocompleteSystem {
    public TrieNode root = new TrieNode();
    public TrieNode p;
    public String userInput = "";

    public AutocompleteSystem(String[] sentences, int[] times) {
        for (int z = 0; z < sentences.length; z++) {
            TrieNode p1 = root;
            String sentence = sentences[z];
            int time = times[z];
            insert(sentence, time);
        }
        p = root;
    }
    
    public List<String> input(char c) {
        List<String> res = new ArrayList<>();
        if (c == '#') {    // Save the user input to the trie and reset p and userInput
            insert(userInput, 1);
            userInput = "";
            p = root;
            return res;
        }
        
        userInput += c;
        c = c == ' ' ? '{' : c;
        if (p == null || p.children[c - 'a'] == null) {    // If the string is not in tht trie tree
            p = null;
            return res;
        }
        
        // Get the top three candidates
        p = p.children[c - 'a'];
        Map<String, Integer> cnt = p.cnt;
        PriorityQueue<si> pq = new PriorityQueue<>(new cmp());
        for (Map.Entry<String, Integer> entry : cnt.entrySet()) {
            pq.offer(new si(entry.getKey(), entry.getValue()));
        }
        for (int i = 0; i < 3 && !pq.isEmpty(); i++)
            res.add(pq.poll().str);
        
        return res;
    }
    
    private void insert(String str, int time) {
        TrieNode p1 = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == ' ')    c = '{';
            if (p1.children[c - 'a'] == null)
                p1.children[c - 'a'] = new TrieNode();
            p1 = p1.children[c - 'a'];
            
            p1.cnt.put(str, p1.cnt.getOrDefault(str, 0) + time);
        }
    }
}

class cmp implements Comparator<si> {
    @Override
    public int compare(si a, si b) {
        if (a.hotDegree != b.hotDegree)
            return b.hotDegree - a.hotDegree;
        else
            return a.str.compareTo(b.str);
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */