class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        List<int[]> bl = new ArrayList<>();
        for (int i = 0; i < B.length; i++)
            bl.add(new int[]{B[i], i});
        Arrays.sort(A);    Collections.sort(bl, (a, b)->a[0] - b[0]);
        
        int[] res = new int[A.length];
        int pa = 0, pb;
        List<Integer> unused = new ArrayList<>();
        for (pb = 0; pb < bl.size() && pa < A.length; pb++) {
            while (pa < A.length && A[pa] <= bl.get(pb)[0]) {
                unused.add(A[pa]);
                pa++;
            }
            if (pa >= A.length)    break;
            res[bl.get(pb)[1]] = A[pa++];
        }
        
        // Fill the rest spaces with unused value from A
        int i = 0;
        for ( ; pb < bl.size(); pb++)
            res[bl.get(pb)[1]] = unused.get(i++);
        
        return res;
    }
}