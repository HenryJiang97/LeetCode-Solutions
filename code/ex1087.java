class Solution {
    public String[] expand(String S) {
        int n = S.length();
        List<String> res = new ArrayList<>();
        
        int i = 0;
        String s = "";
        while (i < n) {
            char c = S.charAt(i);
            if (c == '{') {
                if (!s.equals("")) {
                    addString(res, s);
                    s = "";
                }
                i++;
                List<String> next = new ArrayList<>();
                while (i < n && S.charAt(i) != '}') {
                    char cc = S.charAt(i);
                    if (cc == ',') {
                        next.add(s);
                        s = "";
                    } else    s += cc;
                    i++;
                }
                i++;
                if (!s.equals("")) {
                    next.add(s);
                    s = "";
                }
                if (res.isEmpty())    res = next;
                else    res = combine(res, next);
            }
            else {
                s += c;
                i++;
            }
        }
        if (!s.equals(""))
            addString(res, s);
        
        // Transform list to array
        String[] r = new String[res.size()];
        for (i = 0; i < r.length; i++)
            r[i] = res.get(i);
        Arrays.sort(r);
        return r;
    }
    
    private List<String> combine(List<String> l1, List<String> l2) {
        List<String> combined = new ArrayList<>();
        for (int i = 0; i < l1.size(); i++) {
            for (int j = 0; j < l2.size(); j++) {
                combined.add(l1.get(i) + l2.get(j));
            }
        }
        return combined;
    }
    
    private void addString(List<String> list, String s) {
        if (list.isEmpty()) {
            list.add(s);
            return;
        }
        
        for (int i = 0; i < list.size(); i++) {
            list.set(i, list.get(i) + s);
        }
    }
}