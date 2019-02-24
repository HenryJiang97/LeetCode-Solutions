import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int findJudge(int N, int[][] trust) {
        if (trust.length == 0)    return 1;
        
        ArrayList<Integer> candidates = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Build map
        for (int i = 0; i < trust.length; i++) {
            if (!map.containsKey(trust[i][1]))    map.put(trust[i][1], 1);
            else    {
                map.put(trust[i][1], map.get(trust[i][1]) + 1);
            }
        }
        
        // Get candidates
        for (HashMap.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == N - 1)    candidates.add(entry.getKey());
        }
        
        // Test if candidates are valid (not exist in trust[i][0])
        ArrayList<Integer> backup = new ArrayList<Integer>(candidates);
        for (int candidate : backup) {
            for (int i = 0; i < trust.length; i++) {
                if (candidate == trust[i][0]) {
                    candidates.remove(candidates.indexOf(candidate));
                    break;
                }
            }
            if (candidates.size() == 0)    break;
        }
        
        return (candidates.size() == 0) ? -1 : candidates.get(0);
    }
}