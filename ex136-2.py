class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        return int((sum(set(nums)) * 2 - sum(nums)))


sol = Solution()
print(sol.singleNumber([4, 1, 2, 1, 2]))
