import java.util.List;
import java.util.ArrayList;

class Solution {
    private List<String> result = new ArrayList<String>();
    
    private void dfs(String s, String r, int index, int len) {
        // When there're 4 segment in the string and all characters are included, save to result
        if (len == 4 && index == s.length() - 1) {
            result.add(r);    return;
        } else if (len == 4)    return;
        
        
        String temp = "";
        for (int i = index + 1; i < s.length(); i++) {
            temp += s.charAt(i);
            int value = Integer.valueOf(temp);
            
            // When the segment has a value less equal then 255 and no zero in the front
            if (value <= 255 && temp.equals(Integer.toString(value))) {
                if (len == 0)    dfs(s, temp, i, len + 1);
                else    dfs(s, r + "." + temp, i, len + 1);
            } else
                return;
        } 
    }
    
    
    public List<String> restoreIpAddresses(String s) {
        dfs(s, "", -1, 0);
        
        return result;
    }
}