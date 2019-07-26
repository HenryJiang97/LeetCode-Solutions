class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def DP(self, nums):
        	#Pre-processing
        	if len(nums) == 0:
        		return 0

        	if len(nums) == 1:
        		return nums[0]

        	# if len(nums) == 2:
        	# 	return max(nums[0], nums[1])

        	# if len(nums) == 3:
        	# 	return max(nums[0], nums[1], nums[2])

       		#DP
       		dp = [0 for i in range(len(nums))]

       		dp[0] = nums[0]
       		dp[1] = max(dp[0], nums[1])

       		for i in range(2, len(nums)):
       			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])


       		return dp[-1]


       	#Pre-processing
       	if len(nums) == 0:
       		return 0
       	if len(nums) == 1:
       		return nums[-1]


        if (DP(self, nums) != DP(self, nums[0:-1])) or (DP(self, nums) != DP(self, nums[1:])) or (DP(self, nums[1:]) != DP(self, nums[0:-1])):
        	return max(DP(self, nums[0:-1]), DP(self, nums[1:]))
        else:
        	return DP(self, nums)

sol = Solution()
print(sol.rob([0, 0]))