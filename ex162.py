class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        for i in range(1, len(nums) - 1):
            if (nums[i] > nums[i + 1]) and (nums[i] > nums[i - 1]):
                return i

        if len(nums) == 1:
            return 0

        if len(nums) >= 2:
            if nums[0] > nums[1]:
                return 0

            if nums[len(nums) - 1] > nums[len(nums) - 2]:
                return len(nums) - 1

sol = Solution()
print(sol.findPeakElement([1, 2]))
