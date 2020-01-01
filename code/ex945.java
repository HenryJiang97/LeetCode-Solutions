class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int next = 0, increment = 0;
        for (int a : A) {
            increment += Math.max(next - a, 0);
            next = Math.max(next, a) + 1;
        }
        return increment;
    }
}