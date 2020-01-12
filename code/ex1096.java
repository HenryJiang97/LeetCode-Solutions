class Solution {
    public int i = 0, n;
    
    public List<String> braceExpansionII(String S) {
        n = S.length();
        Set<String> ret = dfs(S);
        List<String> res = new ArrayList<>(ret);
        Collections.sort(res);
        return res;
    }
    
    private Set<String> dfs(String S) {
        Set<String> ret = new HashSet<>();
        Set<String> temp = new HashSet<>();
        String s = "";
        while (i < S.length()) {
            char c = S.charAt(i);
            if (c >= 'a' && c <= 'z') {    // Is alphabet
                s += c;
                i++;
            }
            else {
                if (!s.equals("")) {
                    if (temp.isEmpty()) {
                        temp.add(s);
                        s = "";
                    }
                    else {
                        temp = addString(temp, s);
                        s = "";
                    }
                }
                
                if (c == '{') {
                    i++;
                    Set<String> next = dfs(S);
                    temp = combine(temp, next);
                }
                else if (c == '}') {
                    if (!temp.isEmpty()) {
                        addList(ret, temp);
                        temp.clear();
                    }
                    i++;
                    return ret;
                }
                else if (c == ',') {
                    if (!temp.isEmpty()) {
                        addList(ret, temp);
                        temp.clear();
                    }
                    i++;
                }
            }
        }
        
        if (!s.equals("")) {
            if (temp.isEmpty())    temp.add(s);
            else    temp = addString(temp, s);
        }
        
        if (!temp.isEmpty())    addList(ret, temp);
        
        return ret;
    }
    
    private Set<String> combine(Set<String> l1, Set<String> l2) {
        if (l1.isEmpty())    return l2;
        Set<String> combined = new HashSet<>();
        for (String s1 : l1) {
            for (String s2 : l2) {
                combined.add(s1 + s2);
            }
        }
        return combined;
    }
    
    private void addList(Set<String> res, Set<String> temp) {
        for (String t : temp)
            res.add(t);
    }
    
    private Set<String> addString(Set<String> set, String s) {
        Set<String> res = new HashSet<>();
        for (String se : set) {
            res.add(se + s);
        }
        return res;
    }
}