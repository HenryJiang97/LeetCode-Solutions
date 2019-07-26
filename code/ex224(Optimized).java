import java.util.*;

class Solution {   
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int result = 0;
        int num = 0;    // Store each number
        int sign = 1;    // When the num is positive, sign = 1; Otherwise, -1
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '+') {
                result += sign * num;
                num = 0;    sign = 1;
            }
            
            else if (c == '-') {
                result += sign * num;
                num = 0;    sign = -1;
            }
            
            else if (c == '(') {
                stack.push(result);
                stack.push(sign);    // Store the sign before the parenthese
                num = 0;    sign = 1;    result = 0;
            }
            
            else if (c == ')') {
                result += sign * num;
                
                int si = stack.pop();    // Get the sign before the parenthese
                int n = stack.pop();    // Get the result before the parenthese
                result = result * si + n;
                
                num = 0;    sign = 1;
            }
            
            else if (Character.isDigit(c)) {
                num = 10 * num + (c - '0');
            }
        }
        
        if (num != 0)    result += sign * num;
        
        return result;
    }
}