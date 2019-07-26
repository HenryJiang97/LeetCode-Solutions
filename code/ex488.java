// DFS through hand string

class Solution {
    public int res = Integer.MAX_VALUE;
    
    public int findMinStep(String board, String hand) {
        Map<Character, Integer> handmap = new HashMap<>();
        for (char c : hand.toCharArray())
            handmap.put(c, handmap.getOrDefault(c, 0) + 1);
        
        dfs(board, handmap, 0);
        
        return res == Integer.MAX_VALUE ? -1 : res;
    }
    
    private void dfs(String board, Map<Character, Integer> hand, int cnt) {
        if (board.length() == 0) {
            res = Math.min(res, cnt);
            return;
        }
        
        for (Map.Entry<Character, Integer> entry : hand.entrySet()) {
            char c = entry.getKey();
            if (entry.getValue() == 0)    continue;
            
            hand.put(c, hand.get(c) - 1);
            for (int i = 0; i < board.length(); i++) {
                if (board.charAt(i) != c)    continue;    // Find the same character as c
                if (i > 0 && board.charAt(i) == board.charAt(i - 1))    continue;    // Skip continuous char
                
                // Insert c to i position
                StringBuilder sb = new StringBuilder(board);    sb.insert(i, c);
                
                String newStr = sb.toString();
                newStr = remove(newStr);
                    
                dfs(newStr, hand, cnt + 1);
            }
            hand.put(c, hand.get(c) + 1);
        }
    }
    
    // Remove duplicates over 3
    private String remove(String str) {
        while (true) {
            String newStr = "";
            int p = 0;
            
            while (p < str.length()) {
                int pLast = p;
                while (p < str.length() && str.charAt(p) == str.charAt(pLast))    p++;
                
                if (p - pLast < 3)    newStr = newStr + str.substring(pLast, p);
            }
            
            if (newStr.equals(str))    return newStr;
            str = newStr;
        }
    }
}