class Solution {
    public String minimizeError(String[] prices, int target) {
        PriorityQueue<Double> pq = new PriorityQueue<>();    // Store (ceil - p) - (p - floor)
        double res = 0.0;
        for (String price : prices) {
            double p = Double.parseDouble(price);
            double floor = (double)Math.floor(p);
            double ceil = (double)Math.ceil(p);
            if (floor != ceil)
                pq.add(ceil - p - (p - floor));
            target -= floor;
            res += p - floor;
        }
        
        if (target < 0 || target > pq.size())    return "-1";
        
        while (target > 0) {
            res += pq.poll();
            target--;
        }
        
        return String.format("%3f", res);
    }
}