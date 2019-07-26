class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        try:
            r = nums.index(target)
        except:
            r = -1

        return r

sol = Solution()
print(sol.search([4,5,6,7,0,1,2], 222))