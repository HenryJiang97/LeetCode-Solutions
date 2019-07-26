// Discard the previous digit if it is larger than the current digit

import java.util.*;

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < num.length(); i++) {
            while (!stack.isEmpty() && stack.peek() > num.charAt(i) && k-- > 0) {
                stack.pop();
            }
            stack.push(num.charAt(i));
        }
        
        // If k still > 0, delete rest digits from the back since the last few digits are larger in the stack
        while (k-- > 0) {
            stack.pop();
        }
        
        // System.out.println(stack);
        
        // Convert the stack to string
        StringBuilder sb = new StringBuilder();
        
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        sb.reverse();
        
        // Delete 0 from the head of the stringbuilder
        while (sb.length() > 1 && sb.charAt(0) == '0')
            sb.deleteCharAt(0);
        
        return (sb.length() == 0) ? "0" : sb.toString();
    }
}