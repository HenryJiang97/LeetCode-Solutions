class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        i = 0
        j = 0
        
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    result.append(i)
                    result.append(j)


        return result
            

sol = Solution()

print(sol.twoSum([3,2,4], 6))