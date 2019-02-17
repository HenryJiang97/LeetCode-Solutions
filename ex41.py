class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        i = 1
        while(1):
            if i not in nums:
                return i

            i += 1
        

sol = Solution()
print(sol.firstMissingPositive([3,4,-1,1]))