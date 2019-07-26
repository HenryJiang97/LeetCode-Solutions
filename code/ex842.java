class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        int n = S.length();
        List<Integer> list = new ArrayList<>();
        if (n < 3)    return list;
        
        for (int i = 0; i < n - 2; i++) {
            if (i >= 1 && S.charAt(0) == '0')    continue;
            if (i >= 9)    continue;
            list.add(Integer.parseInt(S.substring(0, i + 1)));
            for (int j = i + 1; j < n - 1; j++) {
                if (j - i >= 2 && S.charAt(i + 1) == '0')    continue;
                if (j - i >= 10)    continue;
                list.add(Integer.parseInt(S.substring(i + 1, j + 1)));
                if (backtracking(list, S, j + 1))    return list;
                list.remove(list.size() - 1);
            }
            list.remove(list.size() - 1);
        }
        
        return new ArrayList<>();
    }
    
    private boolean backtracking(List<Integer> list, String S, int start) {
        boolean res = false;
        for (int i = start; i < S.length(); i++) {
            if (i - start >= 2 && S.charAt(start) == '0')    continue;
            if (i - start >= 10)    continue; 
            
            long current = Long.parseLong(S.substring(start, i + 1));
            if (current > Integer.MAX_VALUE)    continue;
            int curr = (int)current;
            int p1 = list.get(list.size() - 1), p2 = list.get(list.size() - 2);
            
            if (p2 + p1 == curr && i + 1 == S.length()) {
                list.add(curr);
                return true;
            } else if (p2 + p1 == curr) {
                list.add(curr);
                res = backtracking(list, S, i + 1);
                if (res)    return true;
                list.remove(list.size() - 1);
            }
        }
        return false;
    }
}