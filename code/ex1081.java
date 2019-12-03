class Solution {
    public String smallestSubsequence(String text) {
        int n = text.length();
        int[] lastIdx = new int[26];
        for (int i = 0; i < n; i++)
            lastIdx[text.charAt(i) - 'a'] = i;
        
        Stack<Character> stack = new Stack<>();
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            char c = text.charAt(i);
            if (set.contains(c))    continue;
            
            while (!stack.isEmpty() && stack.peek() > c && lastIdx[stack.peek() - 'a'] > i) {
                set.remove(stack.peek());
                stack.pop();
            }
                
            stack.push(c);
            set.add(c);
        }
        
        String res = "";
        while (!stack.isEmpty())
            res = stack.pop() + res;
        
        return res;
    }
}