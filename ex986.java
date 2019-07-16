class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int n1 = A.length, n2 = B.length;
        if (n1 == 0 || n2 == 0)    return new int[0][0];
        int p1 = 0, p2 = 0;
        
        List<int[]> list = new ArrayList<>();
        int start = 0, end = 0;
        while (p1 < n1 && p2 < n2) {
            if (A[p1][1] < B[p2][0])    p1++;
            else if (A[p1][0] > B[p2][1])    p2++;
            else {
                start = Math.max(A[p1][0], B[p2][0]);
                end = Math.min(A[p1][1], B[p2][1]);
                list.add(new int[]{start, end});
                
                if (A[p1][1] > B[p2][1])    p2++;
                else if (A[p1][1] < B[p2][1])    p1++;
                else    {p1++;    p2++;}
            }
        }
        
        // Copy result to array
        int[][] res = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            res[i][0] = list.get(i)[0];
            res[i][1] = list.get(i)[1];
        }
        
        return res;
    }
}