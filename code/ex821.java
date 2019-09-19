// Binary Search

class Solution {
    public int[] shortestToChar(String S, char C) {
        int n = S.length();
        
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (S.charAt(i) == C)
                list.add(i);
        }
        
        // Search
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = list.size() - 1;
            
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (list.get(mid) == i) {
                    res[i] = 0;
                    break;
                } else if (list.get(mid) > i) {
                    if (mid - 1 < 0) {
                        res[i] = list.get(mid) - i;
                        break;
                    }
                    else if (list.get(mid - 1) <= i) {
                        res[i] = Math.min(list.get(mid) - i, i - list.get(mid - 1));
                        break;
                    }
                    hi = mid - 1;
                } else {
                    if (mid + 1 >= list.size()) {
                        res[i] = i - list.get(mid);
                        break;
                    }
                    else if (list.get(mid + 1) >= i) {
                        res[i] = Math.min(list.get(mid + 1) - i, i - list.get(mid));
                        break;
                    }
                    lo = mid + 1;
                }
            }
        }
        
        return res;
    }
