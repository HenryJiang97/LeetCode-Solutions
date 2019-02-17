// Stack

import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;


class Solution {
    public String removeDuplicateLetters(String s) {
        char[] str = s.toCharArray();
        
        // Add the appearence to a map
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : str) {
            if (map.containsKey(c))    map.put(c, map.get(c) + 1);
            else    map.put(c, 1);
        }
        
        
        HashSet<Character> visited = new HashSet<>();
        Stack<Character> stack = new Stack<>();
        
        for (char c : str) {
            map.put(c, map.get(c) - 1);    // Minus 1 to the appearence
            
            if (visited.contains(c))    continue;    // Duplicate char
            
            // Keep lexicographical order
            while (!stack.isEmpty() && c < stack.peek() && map.get(stack.peek()) > 0)
                visited.remove(stack.pop());
            
            visited.add(c);
            stack.push(c);
        }
        
        // Get result
        String r = "";
        for (char c : stack)    r += c;
        return r;
    }
}