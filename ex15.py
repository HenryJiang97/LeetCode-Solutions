class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        nums.sort()
        length = len(nums)
        List = []

        for i in range(0, length - 2):
            for j in range(i + 1, length - 1):
                if ((0 - nums[i] - nums[j]) in nums[j + 1:length + 1:1]):
                    l = [nums[i], nums[j], 0 - nums[i] - nums[j]]
                    if l not in List:
                        List.append(l)
        
        return List
        
sol = Solution()
print(sol.threeSum([-1, 0, 1, 2, -1, -4]))