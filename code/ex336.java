// O(n * k ^ 2); k => length of the longest word

import java.util.*;

class Solution {
    // Method to decide if a string is a palindrome
    private boolean isPalindrome(String word) {
        int lo = 0, hi = word.length() - 1;
        while (lo <= hi)
            if (word.charAt(lo++) != word.charAt(hi--))    return false;
        return true;
    }
    
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            map.put(words[i], i);
        }
        
        for (int i = 0; i < words.length; i++) {
            // Empty word can be combined with any word except itself
            if (words[i].equals("")) {
                for (int j = 0; j < words.length; j++) {
                    if (j != i && isPalindrome(words[j]))
                        res.add(new ArrayList<Integer>(Arrays.asList(i, j)));
                }
            }
            
            for (int c = 0; c < words[i].length(); c++) {
                String strHead = words[i].substring(0, c);
                String strTail = words[i].substring(c, words[i].length());
                String strHeadReverse = new StringBuilder(strHead).reverse().toString();
                String strTailReverse = new StringBuilder(strTail).reverse().toString();
                
                // If head part is a palindrome, find tail part in the map
                if (isPalindrome(strHead)) {
                    if (map.containsKey(strTailReverse) && map.get(strTailReverse) != i)
                        res.add(new ArrayList<Integer>(Arrays.asList(map.get(strTailReverse), i)));
                }
                // If tail part is a palindrome, find head part in the map
                if (isPalindrome(strTail)) {
                    if (map.containsKey(strHeadReverse) && map.get(strHeadReverse) != i)
                        res.add(new ArrayList<Integer>(Arrays.asList(i, map.get(strHeadReverse))));
                }
                
            }
        }
        
        return res;
    }
}