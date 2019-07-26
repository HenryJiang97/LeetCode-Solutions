class Solution
{
	public int totalHammingDistance(int[] A)
	{
        int n = A.length;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i != j)
                    cnt += Integer.bitCount(A[i] ^ A[j]);
            }
        }
        
        return cnt;
    }
}