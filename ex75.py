class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        for i in range(1, len(nums)):
            p = nums[i]

            j = i - 1
            while (j >= 0) & (nums[j] > p):
                nums[j + 1] = nums[j]
                j -= 1

            nums[j + 1] = p

        return nums


sol = Solution()
print(sol.sortColors([2, 0, 2, 1, 1, 0]))
