class Solution {    
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y == z)    return true;
        if (x + y < z)    return false;     
        int gcp = GCP(x, y);

        return (x != 0 && z % x == 0) || (y != 0 && z % y == 0) || (gcp != 0 && z % gcp == 0);
    }
    
    // Get the greatest common divisor
    public int GCP(int x, int y) {
        for (int i = Math.min(x, y); i >= 1; i--) {
            if (x % i == 0 && y % i == 0)    return i;
        }     
        return 0;
    }
}