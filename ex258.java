class Solution {
    public static int getDigitsAndAdd(int num) {
        int sum = 0;
        
        while (num > 0) {
            sum = sum + num % 10;
            num /= 10;
        }
        
        return sum;
    }
    
    
    public int addDigits(int num) {
        int digitsSum = getDigitsAndAdd(num);
        
        while (digitsSum >= 10) {
            digitsSum = getDigitsAndAdd(digitsSum);
        }
        
        return digitsSum;
    }
}