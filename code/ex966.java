class Solution {
    private Set<Character> vowel;
    
    public String[] spellchecker(String[] wordlist, String[] queries) {
        List<Character> vowelList = new ArrayList<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        vowel = new HashSet<>(vowelList);
        
        // Build maps for further use
        Map<String, Integer> original = new HashMap<>();
        Map<String, Integer> groupByCapital = new HashMap<>();
        Map<String, Integer> groupByVowel = new HashMap<>();
        
        for (int i = 0; i < wordlist.length; i++) {
            String word = wordlist[i];
            
            original.putIfAbsent(word, i);
            
            String lowerCase = word.toLowerCase();
            groupByCapital.putIfAbsent(lowerCase, i);
            
            String vowel = getVowel(word).toLowerCase();
            groupByVowel.putIfAbsent(vowel, i);
        }
        
        // Get correct words
        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String query = queries[i];
            if (original.containsKey(query)) {
                res[i] = wordlist[original.get(query)];
                continue;
            }
            if (groupByCapital.containsKey(query.toLowerCase())) {
                res[i] = wordlist[groupByCapital.get(query.toLowerCase())];
                continue;
            }
            String vowel = getVowel(query).toLowerCase();
            if (groupByVowel.containsKey(vowel)) {
                res[i] = wordlist[groupByVowel.get(vowel)];
                continue;
            }
            res[i] = "";
        }

        return res;
    }
    
    private String getVowel(String word) {
        StringBuilder sb = new StringBuilder(word);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (vowel.contains(c))    sb.setCharAt(i, '*');
        }
        return sb.toString();
    }
}