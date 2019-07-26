#f(0) = nums[0]
#f(1) = max(nums[1], nums[0])
#f(2) = max(f(1), f(0) + nums(2))
#f(3) = max(f(2), f(1) + nums(3))
#...
#f(n) = max(f(n-1), f(n - 2) + nums(n))


class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        #Pre-processing
        if len(nums) == 0:
            return 0

        if len(nums) == 1:
            return nums[0]


        #DP
        f = [0 for i in range(len(nums))]

        f[0] = nums[0]
        f[1] = max(f[0], nums[1])


        for i in range(2, len(nums)):
            f[i] = max(f[i - 1], f[i - 2] + nums[i])



        return f[-1]


sol = Solution()
print(sol.rob([2,7,9,3,1]))
