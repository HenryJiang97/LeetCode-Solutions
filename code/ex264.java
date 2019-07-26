class Solution {
    public int nthUglyNumber(int n) {
        int[] uglyNum = new int[n];

        // Init
        int m2 = 0;
        int m3 = 0;
        int m5 = 0;
        uglyNum[0] = 1;


        for (int i = 1; i < n; i++) {
            // Get the next ugly number
            uglyNum[i] = Math.min(Math.min(uglyNum[m2] * 2, uglyNum[m3] * 3), uglyNum[m5] * 5);

            // Update m2, m3, m5 if necessary (If uglyNum[m2] is the minimum, m2++; Same as m3 and m5)
            m2 += (uglyNum[i] == uglyNum[m2] * 2) ? 1 : 0;
            m3 += (uglyNum[i] == uglyNum[m3] * 3) ? 1 : 0;
            m5 += (uglyNum[i] == uglyNum[m5] * 5) ? 1 : 0;
        }

        return uglyNum[n - 1];
    }
}