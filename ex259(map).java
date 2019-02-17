import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] singleNumber(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();

        // Add key and value to a map
        for (int i : nums) {
            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else 
                map.put(i, 1);
        }


        // Search the map for key with value = 1
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1)
                list.add(entry.getKey());
        }

        // Copy items in the ArrayList to an array
        int[] r = new int[list.size()];
        
        for (int i = 0; i < r.length; i++)
            r[i] = list.get(i);


        return r;
    }
}