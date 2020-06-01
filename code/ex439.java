class Solution {
    public String parseTernary(String s) {
        int n = s.length();
        
        Stack<String> stk = new Stack<>();
        String temp = "";
        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ':') {
                stk.push(temp);    temp = "";
            } else if (c == '?') {
                stk.push(temp);    temp = "";
                char c1 = s.charAt(i - 1);
                String t = stk.pop(), f = stk.pop();
                temp = c1 == 'T' ? t : f;
                i--;
            } else {
                temp += c;
            }
        }
        
        return temp;
    }
}