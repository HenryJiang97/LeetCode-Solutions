import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        Stack<String> res = new Stack<>();
        String[] p = path.split("/");

        
        for (String s : p) {
            if (s.equals("") || s.equals("."))    continue;
            if (s.equals("..")) {
                if (!res.isEmpty())    res.pop();   
            } else {
                res.add(s);
            }

        }
        
        // Combine to result
        if (res.size() == 0)    return "/";
        String result = "";
        for (String r : res) {
            result = result + "/" + r;
        }
        
        return result;
    }
}