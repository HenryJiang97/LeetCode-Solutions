class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> jewels = new HashSet<>();
        for (char c : J.toCharArray())    jewels.add(c);
        int cnt = 0;
        for (char c : S.toCharArray())    if (jewels.contains(c))    cnt++;
        return cnt;
    }
}