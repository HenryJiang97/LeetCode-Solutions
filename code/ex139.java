// Backtracking + DP(memo)

import java.util.List;
import java.util.HashMap;

class Solution {
    public boolean backtracking(String s, List<String> wordDict, HashMap<String, Boolean> dp) {
        // Get value from dp dictionary
        if (dp.containsKey(s))    return dp.get(s);
        
        // Add to list if s itself is in the wordDict
        if (wordDict.contains(s))    return true;
        
        for (int i = 0; i < s.length(); i++) {
            String end = s.substring(i + 1, s.length());
            
            if (wordDict.contains(end)) {
                if (backtracking(s.substring(0, i + 1), wordDict, dp))    return true;
            }      
        }
        
        dp.put(s, false);    // Update dp dictionary
        return false;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        HashMap<String, Boolean> dp = new HashMap<>();
        
        return backtracking(s, wordDict, dp);
    }
}