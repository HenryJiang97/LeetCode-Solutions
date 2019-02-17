class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []

        for i in range(0, len(nums)):
            if nums[i] == target:
                result.append(i)
                break

        for i in range(0, len(nums)):
            if nums[len(nums) - i - 1] == target:
                result.append(len(nums) - i - 1)
                break

        if result == []:
            return [-1, -1]

        return result
            

sol = Solution()
print(sol.searchRange([5,7,7,8,8,10], 6))