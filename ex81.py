class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """

        if target in nums:
            return True
        else:
            return False

sol = Solution()
print(sol.search([2, 5, 6, 0, 0, 1, 2], 0))
