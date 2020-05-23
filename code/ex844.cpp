class Solution {
    public boolean backspaceCompare(String S, String T) {
        int ns = S.length(), nt = T.length();
        
        Stack<Character> stackT = getStack(S);
        Stack<Character> stackS = getStack(T);
        
        while (!stackT.isEmpty() && !stackS.isEmpty()) {
            if (stackT.pop() != stackS.pop())    return false;
        }
        
        return stackT.isEmpty() && stackS.isEmpty();
    }
    
    private Stack<Character> getStack(String s) {
        Stack<Character> stack = new Stack();
        for (char c : s.toCharArray()) {
            if (c == '#') {
                if (!stack.isEmpty())    stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack;
    }
}