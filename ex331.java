import java.util.Stack;

class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] pre = preorder.split(",");
    
        // Special situation
        if (pre.length == 1)    
            return (pre[0].equals("#")) ? true : false;
        if (pre.length == 2)    return false;
        
        
        // Build a stack to store tree root
        Stack<String> stack = new Stack<String>();
        stack.push(pre[0]);    stack.push(pre[1]);
        
        for (int i = 2; i < pre.length; i++) {
            stack.push(pre[i]);
            
            while (stack.get(stack.size() - 1).equals("#") && stack.get(stack.size() - 2).equals("#") && !stack.get(stack.size() - 3).equals("#")) {
                stack.pop();    stack.pop();    stack.pop();
                
                if (stack.size() == 0 && i == pre.length - 1)    return true;
                if (stack.size() == 0 && i != pre.length - 1)    return false;
                
                stack.push("#");
                
                if (stack.size() < 3)    break;
            }
        }   
        return false;
    }
}