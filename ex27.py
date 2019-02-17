class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        i = 0
        j = 0
        while j < len(nums):
            if nums[j] == val:
                if nums[i] != val:
                    i = j
                j += 1
            else:
                if nums[i] == val:
                    nums[i] = nums[j]
                    nums[j] = val
                    i += 1
                j += 1
                
        print(nums)
        #When input = [n], val = n, return 1
        if len(nums) == 1:
            if nums[0] != val:
                return 1
        
        #If there is no val in the list, return the length of the list
        if len(nums) != 0:
            if (i == 0) & (nums[0] != val):
                return len(nums)

        return i

sol = Solution()
print(sol.removeElement([], 0))