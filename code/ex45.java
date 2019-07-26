class Solution {
    public int jump(int[] nums) {       
        int len = nums.length;
        // Special situation
        if (len == 1)   return 0;
        

        int[] final_pos = new int[len - 1];
        
        // Build an array to record the last possible position each jump can reach
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] + i >= len)      final_pos[i] = len - 1;
            else    final_pos[i] = nums[i] + i;
        }
        
        
        int i = 0;
        int jump = 0;
        int max;
        while (true) {
            jump++;
            if (final_pos[i] == len - 1)    break;  
            
            max = i + 1;
            for (int j = i + 1; j <= final_pos[i]; ++j) 
                if (final_pos[j] >= final_pos[max])
                    max = j;
            
            i = max;
        }
         
        
        return jump;
    }
}