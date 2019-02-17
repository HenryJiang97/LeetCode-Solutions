class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);
            
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(j) == a) {
                    if (t.charAt(j) != b)
                        return false;
                }else {
                    if (t.charAt(j) == b)
                        return false;
                }
            }
        }
        
        
        return true;
    }
}