class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = None

        for i in range(0, len(nums)):
            if target <= nums[i]:
                result = i
                break
        
        #If target is larger than any items in the sorted list, return the last index + 1
        if result == None:
            return len(nums)
        else:
            return result

sol = Solution()
print(sol.searchInsert([1,3,5,6], 0))