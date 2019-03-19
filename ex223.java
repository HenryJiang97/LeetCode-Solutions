class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (Math.max(B, F) > Math.min(D, H) || Math.max(A, E) > Math.min(C, G))
            return (D - B) * (C - A) + (H - F) * (G - E);
        else
            return (D - B) * (C - A) + (H - F) * (G - E) - (Math.abs(Math.min(D, H) - Math.max(B, F)) * Math.abs(Math.min(G, C) - Math.max(E, A)));
    }
}