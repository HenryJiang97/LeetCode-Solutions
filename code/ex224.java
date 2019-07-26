import java.util.*;

class Solution {
    public void doCalculation(Stack<String> num) {
        while (num.size() > 1 && num.peek() != "(") {
            int num2 = Integer.parseInt(num.pop());
            if (num.peek() == "(") {
                num.pop();
                if (!num.isEmpty() && num.peek() == "-") {
                    num.pop();
                    num.push(String.valueOf(-num2));
                }
                else    num.push(String.valueOf(num2));
                break;
            }
            int num1 = Integer.parseInt(num.pop());
            
            num.push(String.valueOf(num1 + num2));
        }
    }
    
    
    public int calculate(String s) {
        Stack<String> num = new Stack<>();

        boolean sign = false;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ')')    doCalculation(num);
            else if (c == '-') {
                if (s.charAt(i + 1) == '(')    num.push("-");
                else    sign = true;
            }
            else if (c == '(')    num.add("(");
            else if (c >= 48 && c <= 57) {
                String n = "";
                while (i < s.length() && s.charAt(i) >= 48 && s.charAt(i) <= 57) {
                    n += Character.toString(s.charAt(i));
                    i++;
                }
                
                if (sign)    num.add("-" + n);
                else    num.add(n);
                
                sign = false;    i--;
            }
        }
        
        doCalculation(num);
        
        return Integer.parseInt(num.pop());
    }
}