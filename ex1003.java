import java.util.Stack;

class Solution {
    public boolean isValid(String S) {
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < S.length(); i++) {
            stack.push(S.charAt(i));
            if (S.charAt(i) == 'c') {
                if (stack.size() < 3 || stack.get(stack.size() - 2) != 'b' || stack.get(stack.size() - 3) != 'a')    return false;
                else {stack.pop(); stack.pop(); stack.pop();}
            }
        }
        
        return (stack.size() == 0) ? true : false;
    }
}