class Solution {
    public int minAddToMakeValid(String S) {
        int cnt = 0;
        Stack<Character> stack = new Stack();
        for (char c : S.toCharArray()) {
            if (c == '(')    stack.push('(');
            else {
                if (stack.isEmpty())    cnt++;
                else    stack.pop();
            }
        }
        return cnt + stack.size();
    }
}