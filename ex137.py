class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        return int((sum(set(nums)) * 3 - sum(nums)) / 2)

sol = Solution()
print(sol.singleNumber([0, 1, 0, 1, 0, 1, 99]))
