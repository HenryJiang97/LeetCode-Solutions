import java.util.*;

class Solution {
    public List<String> commonChars(String[] A) {
        ArrayList<Character> c = new ArrayList<>();
        
        for (int i = 0; i < A[0].length(); i++) {
            c.add(A[0].charAt(i));
        }

        
        for (int i = 1; i < A.length; i++) {
            ArrayList<Character> n = new ArrayList<>();
            for (int j = 0; j < A[i].length(); j++) {
                if (c.contains(A[i].charAt(j))) {
                    n.add(A[i].charAt(j));
                    c.remove(c.indexOf(A[i].charAt(j)));
                }
            }
            
            c = n;
        }

        List<String> result = new ArrayList<>();
        for (Character ch : c) {
            result.add(Character.toString(ch));
        }
        
        
        return result;
    }
}