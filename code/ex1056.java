class Solution {
    public boolean confusingNumber(int N) {
        int[] reflect = new int[]{0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
        int newN = 0;
        String n = String.valueOf(N);
        for (int i = n.length() - 1; i >= 0; --i) {
            int d = n.charAt(i) - '0';
            if (d == 0 || d == 1 || d == 6 || d == 8 || d == 9)
                newN = newN * 10 + reflect[d];
            else
                return false;
        }
        return !(newN == N);
    }
}