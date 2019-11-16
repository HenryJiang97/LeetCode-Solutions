class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        int n = queries.length;
        List<Boolean> res = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String q = queries[i];
            
            int p1 = 0, p2 = 0;
            boolean sign = true;
            while (p1 < q.length() && p2 < pattern.length()) {
                while (p1 < q.length() && q.charAt(p1) != pattern.charAt(p2)) {
                    if (q.charAt(p1) >= 'A' && q.charAt(p1) <= 'Z') {
                        sign = false;
                        break;
                    }
                    p1++;
                }
                if (!sign)    break;
                if (p1 >= q.length())    break;
                p1++;    p2++;
            }
            if (!sign) {
                res.add(sign);
                continue;
            }

            if (p1 >= q.length() && p2 < pattern.length()) {
                res.add(false);
                continue;
            }
            
            // Judge if the suffix in q has capital letter
            while (p1 < q.length()) {
                if (q.charAt(p1) >= 'A' && q.charAt(p1) <= 'Z') {
                    sign = false;
                    break;
                }
                p1++;
            }
            res.add(sign);
        }
        
        return res;
    }
}