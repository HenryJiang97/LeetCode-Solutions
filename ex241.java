import java.util.*;

class Solution {
    public List<Integer> divide (String input) {
        List<Integer> res = new ArrayList<>();  
        int len = input.length();
        boolean sign = true;   // If true => There's only one single num in the string
        
        for (int i = 0; i < len; i++) {
            if (!Character.isDigit(input.charAt(i))) {
                sign = false;
                
                // Recursion to left and right substrings
                List<Integer> left = divide(input.substring(0, i));
                List<Integer> right = divide(input.substring(i + 1, len));
                
                for (int num1 : left) {
                    for (int num2 : right) {
                        if (input.charAt(i) == '+')    res.add(num1 + num2);
                        else if (input.charAt(i) == '-')    res.add(num1 - num2);
                        else if (input.charAt(i) == '*')    res.add(num1 * num2);
                    }
                }     
            } 
        }
        
        // Calculate the single number in the string
        if (sign) {
            int num = 0;
            for (int i = 0; i < len; i++)    num = num * 10 + (input.charAt(i) - '0');
            res.add(num);
        }          
        
        return res;
    }
    
    
    public List<Integer> diffWaysToCompute(String input) {
        return divide(input);
    }
}