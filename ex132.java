// DP: 1) 2d-dp:ifP => if palindrome between i and j
//     2) 1d-dp:N => the number of partition before i

class Solution {
    public int minCut(String s) {
        int[] N = new int[s.length()];
        boolean[][] ifP = new boolean[s.length()][s.length()];
        
        for (int i = 0; i < s.length(); i++) {
            int min = Integer.MAX_VALUE;
            for (int j = i; j >= 0; j--) {
                // Judge if substring between j and i is a palindrome
                if (s.charAt(j) == s.charAt(i) && (i - j <= 1 || ifP[j + 1][i - 1])) {
                    ifP[j][i] = true;
                    if (j == 0)    min = 0;
                    else    min = Math.min(min, N[j - 1] + 1);
                }
            }
            N[i] = min;
        }
        
        return N[s.length() - 1];
    }
}