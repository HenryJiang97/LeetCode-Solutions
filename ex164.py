class Solution:
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if len(nums) < 2:
            return 0

        nums.sort()

        maximum = 0
        for i in range(len(nums) - 1):
            if nums[i + 1] - nums[i] > maximum:
                maximum = nums[i + 1] - nums[i]

        return maximum
        
sol = Solution()
print(sol.maximumGap([3,6,9,1]))
