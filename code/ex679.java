// Backtracking

class Solution {
    public boolean judgePoint24(int[] nums) {
        List<Double> list = new ArrayList<>();
        for (int num : nums)    list.add((double)num);
        return backtracking(list);
    }
    
    private boolean backtracking(List<Double> list) {
        if (list.size() == 0)    return false;
        if (list.size() == 1 && Math.abs(list.get(0) - 24) < 1e-4)    return true;
        else if (list.size() == 1)    return false;
        
        // Random pick two distinct num for operation
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (i == j)    continue;
                
                double num1 = list.get(i), num2 = list.get(j);
                List<Double> newlist = new ArrayList();
                
                // Add the rest nums to the newlist
                for (int z = 0; z < list.size(); z++) {
                    if (z != i && z != j)    newlist.add(list.get(z));
                }
                
                // Do four operations to the selected two nums
                for (int k = 0; k < 4; k++) {
                    //'+' and '*' operations are needed only once, skip when num1 > num2
                    if (k < 2 && num1 > num2)    continue;
                    if (k == 0)    newlist.add(num1 + num2);
                    if (k == 1)    newlist.add(num1 * num2);
                    
                    if (k == 2)    newlist.add(num1 - num2);
                    if (k == 3) {
                        if (num2 != 0)    newlist.add(num1 / num2);
                        else    continue;
                    }
                    
                    // DFS
                    if (backtracking(newlist))    return true; 
                
                    newlist.remove(newlist.size() - 1);    // Remove the last num added
                }
            }
        }
        return false;
    }
}