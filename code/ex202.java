class Solution {
    public boolean isHappy(int n) {
        Set<Integer> visited = new HashSet<>();
        visited.add(n);
        while (n != 1) {
            n = getSum(n);
            if (visited.contains(n))    return false;
            visited.add(n);
        }
        return n == 1;
    }
    
    private int getSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }
}