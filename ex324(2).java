import java.util.Arrays;

class Solution {
    public void wiggleSort(int[] nums) {
        // Special situation
        if (nums.length == 0 || nums.length == 1)    return;

        // Duplicate the array and sort
        int[] backup = Arrays.copyOf(nums, nums.length);
        // Arrays库中应该有内容复制的成员函数，或者是用内存复制的方法，会比用单循环一个一个元素复制快很多
        Arrays.sort(backup);    // 用Arrays的sort函数是个好主意

        // Divide the sorted array into 2 pieces from the middle
        // 你的解题方法很不错，我改一点点：把数组分成两段，总长度length是偶数个的时候，第一段0到length/2-1，第二段length/2到length-1；length是奇数个的时候，第一段0到length/2，第二段length/2+1到length-1.
        int p1 = 0;
        int p2 = (nums.length % 2 == 0) ? (nums.length / 2) : (nums.length / 2 + 1);
        // 利用整数类型整除的特性，也可以简化如下：
        int p2 = (nums.length + 1) / 2;

        for (int i = 0; i < nums.length / 2 - 1; i += 2)  {
            nums[i] = backup[p1++];
            nums[i+1] = backup[p2++];
        }
        if (nums.length % 2 <> 0)  {
            nums[nums.length-1] = backup[p1];
        }
    }
}