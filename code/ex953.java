class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] dict = new int[26];
        for (int i = 0; i < order.length(); i++)
            dict[order.charAt(i) - 'a'] = i;
        
        for (int i = 0; i < words.length - 1; i++) {
            String s1 = words[i], s2 = words[i + 1];
            
            int p = 0;
            for(p = 0; p < Math.min(s1.length(), s2.length()); ++p) {
                if (s1.charAt(p) != s2.charAt(p)) {
                    if (dict[s1.charAt(p) - 'a'] > dict[s2.charAt(p) - 'a'])    return false;
                    else    break;
                }
            }
            
            if (p == Math.min(s1.length(), s2.length()) && s1.length() > s2.length())    return false;
        }
        
        return true;
    }
}