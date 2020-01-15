class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        int n = shifts.length;
        int sum = 0;
        String s = "";
        for (int i = n - 1; i >= 0; i--) {
            sum = (sum + shifts[i]) % 26;
            int c = (S.charAt(i) - 'a' + sum) % 26;
            s = (char)(c + 'a') + s;
        }
        return s;
    }
}