class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        for i in range(k):  nums.insert(0, nums.pop(-1))

        return nums

sol = Solution()
print(sol.rotate([-1, -100, 3, 99], 2))
