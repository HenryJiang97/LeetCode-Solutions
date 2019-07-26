import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();
        
        for (String s : tokens)
            if (!(s.length() == 1 && s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")))
                stack.push(s);
            else
                if (s.equals("+"))
                    stack.push(Integer.toString(Integer.parseInt(stack.pop()) + Integer.parseInt(stack.pop())));
                else if (s.equals("-"))
                    stack.push(Integer.toString(-(Integer.parseInt(stack.pop()) - Integer.parseInt(stack.pop()))));
                else if (s.equals("*"))
                    stack.push(Integer.toString(Integer.parseInt(stack.pop()) * Integer.parseInt(stack.pop())));
                else if (s.equals("/")) {
                    int b = Integer.parseInt(stack.pop());
                    int a = Integer.parseInt(stack.pop());
                    stack.push(Integer.toString(a / b));
                }

        
        return Integer.parseInt(stack.pop());
    }
}