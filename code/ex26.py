class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        i = 0
        j = 1
        while j < len(nums):
            if nums[j] == nums[i]:
                j += 1
            else:
                nums[i + 1] = nums[j]
                i += 1
                j += 1
        
        if nums == []:
            return 0
        else:
            return i + 1


sol = Solution()
print(sol.removeDuplicates([]))