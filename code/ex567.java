class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2)    return false;
        
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        
        // Get chars in string s1
        for (int i = 0; i < n1; i++) {
            cnt1[s1.charAt(i) - 'a']++;
            cnt2[s2.charAt(i) - 'a']++;
        }

        // Count the matched chars from 'a' to 'z'
        int match = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] == cnt2[i])    match++;
        }
        if (match == 26)    return true;
        
        // Slide the window to the right
        int lo = 0, hi = n1;
        while (hi < n2) {
            char chi = s2.charAt(hi++);
            char clo = s2.charAt(lo++);
            
            // Add next char
            if (cnt2[chi - 'a'] == cnt1[chi - 'a'])    match--;
            cnt2[chi - 'a']++;
            if (cnt2[chi - 'a'] == cnt1[chi - 'a'])    match++;
            
            // Delete prev char
            if (cnt2[clo - 'a'] == cnt1[clo - 'a'])    match--;
            cnt2[clo - 'a']--;
            if (cnt2[clo - 'a'] == cnt1[clo - 'a'])    match++;

            if (match == 26)    return true;
        }
        
        return false;
    }
}