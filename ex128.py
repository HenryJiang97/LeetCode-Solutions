class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if len(nums) == 0:
            return 0

        nums.sort()

        length = []
        l = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                l += 1
            elif nums[i] == nums[i - 1]:
                continue
            else:
                length.append(l)
                l = 1
                
        length.append(l)

        return max(length)

sol = Solution()
print(sol.longestConsecutive([1,0,2,1]))
