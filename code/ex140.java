import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public List<String> append(List<String> front, String end) {
        List<String> appendedList = new ArrayList<>();
        
        for (String f : front) {
            appendedList.add(f + " " + end);
        }
        
        return appendedList;
    }
    
    
    public List<String> backtracking(String s, List<String> wordDict, HashMap<String, List<String>> dp) {
        // Get value from dp dictionary
        if (dp.containsKey(s))    return dp.get(s);
        
        // Store all possibilities for String s
        List<String> list = new ArrayList<>();
        
        // Add to list if s itself is in the wordDict
        if (wordDict.contains(s))    list.add(s);
        
        for (int i = 0; i < s.length(); i++) {
            String end = s.substring(i + 1, s.length());
            
            if (wordDict.contains(end)) {
                List<String> front = new ArrayList<String>(backtracking(s.substring(0, i + 1), wordDict, dp));
                front = append(front, end);
                
                for (String f : front)    list.add(f);
            }      
        }
        
        dp.put(s, list);    // Update dp dictionary
        return list;
    }
                
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashMap<String, List<String>> dp = new HashMap<>();
        
        List<String> result = backtracking(s, wordDict, dp);
        
        return result;
    }
}