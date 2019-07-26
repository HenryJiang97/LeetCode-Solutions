class Solution {
    public double r, xc, yc;

    public Solution(double radius, double x_center, double y_center) {
        this.r = radius;
        this.xc = x_center;
        this.yc = y_center;
    }
    
    public double[] randPoint() {
        Random rand = new Random();
        double rx = rand.nextDouble();
        double ry = rand.nextDouble();
        
        // Get positive random double with is within 1 distance from (0,0)
        while (Math.pow(rx, 2) + Math.pow(ry, 2) > 1) {
            rx = rand.nextDouble();
            ry = rand.nextDouble();
        }
        
        // Add random negative coordinate
        rx = rand.nextInt(2) == 1 ? rx : -rx;
        ry = rand.nextInt(2) == 1 ? ry : -ry;
        
        // Get corrdinate
        double[] res = new double[2];
        res[0] = xc + rx * r;
        res[1] = yc + ry * r;
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */