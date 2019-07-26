class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        for i in range(0, len(nums) - 1):
            if nums[i + 1] < nums[i]:   return nums[i + 1]
            
        return nums[0]

sol = Solution()
print(sol.findMin([4,5,6,7,0,1,2]))