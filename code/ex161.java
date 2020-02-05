class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int ns = s.length(), nt = t.length();
        if (Math.abs(ns - nt) > 1)    return false;
        int cnt = 0, ps = 0, pt = 0;
        while (ps < ns && pt < nt) {
            if (s.charAt(ps) != t.charAt(pt)) {
                cnt++;
                if (ns == nt) {ps++;    pt++;}
                else if (ns < nt)    pt++;
                else    ps++;
            } else {
                ps++;    pt++;
            }
            if (cnt > 1)    return false;
        }
        cnt += ns - ps + nt - pt;
        return cnt == 1;
    }
}