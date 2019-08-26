class Solution {
    public int s = 0, n;
    
    public boolean parseBoolExpr(String expression) {
        n = expression.length();
        char[] exp = expression.toCharArray();
        return recurrsion(exp);
    }
    
    private boolean recurrsion(char[] exp) {
        while (s < n) {
            if (exp[s] == '!') {
                s += 2;
                boolean res = !recurrsion(exp);
                s++;
                return res;
            }
            if (exp[s] == 't')    {s++;    return true;}
            if (exp[s] == 'f')    {s++;    return false;}
            
            // When meets '&' or '|'
            boolean isAnd = exp[s] == '&' ? true : false;
            boolean res = isAnd;
            s += 2;
            
            while (true) {
                if (exp[s] == ')')    {s++;    break;}
                else if (exp[s] == ',')    s++;
                else {
                    if (isAnd)    res &= recurrsion(exp);
                    else    res |= recurrsion(exp);
                }
            }
            
            return res;
        }
        
        return true;
    }
}