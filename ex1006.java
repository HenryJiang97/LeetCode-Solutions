import java.util.*;

class Solution {
    public int clumsy(int N) {
        // Special situations
        if (N < 4) {
            if (N == 3)    return 6;
            else if (N == 2)    return 2;
            else if (N == 1)    return 1;
            else if (N == 0)    return 0;
        }


        List<Integer> list = new ArrayList<>();       

        list.add(N * (N - 1) / (N - 2) + (N - 3));
        N -= 4;
           
        int len = N;
        for (int i = 0; i < len / 4; i++) {
            list.add(N * (N - 1) / (N - 2) - (N - 3));
            N -= 4;
        }
        
        // Deal with rest of the equation
        if (N == 3)
            list.add(6);
        else if (N == 2)
            list.add(2);
        else if (N == 1)
            list.add(1);
        
            
        // Do minus for the final result
        int result = list.get(0);
        for (int i = 1; i < list.size(); i++)
            result -= list.get(i);
        
        return result;
    }
}