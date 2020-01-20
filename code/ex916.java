class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] cnt = new int[26];
        for (String b : B) {
            int[] temp = new int[26];
            for (char c : b.toCharArray())
                temp[c - 'a']++;
            for (int i = 0; i < 26; i++)
                cnt[i] = Math.max(cnt[i], temp[i]);
        }
        
        List<String> res = new ArrayList<>();
        for (String a : A) {
            int[] temp = new int[26];
            for (char c : a.toCharArray())
                temp[c - 'a']++;
            boolean valid = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < cnt[i])    valid = false;
            }
            if (valid)    res.add(a);
        }
        return res;
    }
}