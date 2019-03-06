import java.util.List;
import java.util.ArrayList;

class Solution {
    private void dfs(List<List<Integer>> result, List<Integer> combination, int k, int n, int lo, int sum) {
        // Get a valid solution
        if (sum == n && combination.size() == k) {
            result.add(new ArrayList<Integer>(combination));
            return;
        }
        
        for (int i = lo + 1; i <= 9; i++) {
            if (sum + i > n)    return;
                
            sum += i;
            combination.add(i);
            dfs(result, combination, k, n, i, sum);
            
            // Recover combination and sum to former state
            combination.remove(combination.size() - 1);
            sum -= i;
        }
    }
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        
        dfs(result, new ArrayList<Integer>(), k, n, 0, 0);
        
        return result;
    }
}