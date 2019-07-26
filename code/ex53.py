class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        global_max = local_max = float('-inf')
                
        for num in nums:
            local_max = max(num, local_max + num)
            global_max = max(global_max, local_max)
        
        return global_max

sol = Solution()
print(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))