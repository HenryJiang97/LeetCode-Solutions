class Solution {
    public int findLUSlength(String[] strs) {
        int n = strs.length;
        TreeMap<Integer, List<String>> map = new TreeMap<>(Collections.reverseOrder());
        
        for (String str : strs) {
            if (map.containsKey(str.length())) {
                List<String> list = new ArrayList<>(map.get(str.length()));
                list.add(str);
                map.put(str.length(), list);
            } else {
                List<String> list = Arrays.asList(str);
                map.put(str.length(), list);
            }
        }
        
        String last = " ";
        for (Map.Entry<Integer, List<String>> entry : map.entrySet()) {
            List<String> list = entry.getValue();
            if (list.size() == 1 && !isSubsequence(last, list.get(0)))    return entry.getKey();

            for (int i = 0; i < list.size(); i++) {
                boolean ifHasSame = false;
                for (int j = 0; j < list.size(); j++) {
                    if (i == j)    continue;
                    if (list.get(i).equals(list.get(j))) {
                        ifHasSame = true;
                        break;
                    }
                }
                if (!ifHasSame && !isSubsequence(last, list.get(i)))
                    return entry.getKey();
            }
            
            last = list.get(0);
        }
        
        return -1;
    }
    
    // Judge if s is a subsequence of l
    private boolean isSubsequence(String l, String s) {
        int pl = 0, ps = 0;
        while (ps < s.length()) {
            if (s.charAt(ps) != l.charAt(pl))    pl++;
            else {pl++;    ps++;}
            if (pl >= l.length())     break;
        }
        if (pl >= l.length() && ps < s.length())    return false;
        else    return true;
    }
}