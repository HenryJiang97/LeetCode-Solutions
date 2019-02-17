class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        #Specific situation
        if nums == []:
            return 0

        #Initialization
        recorder = nums[0]
        counter = 1
        i = 1

        #Loop through the list
        while i < len(nums):
            if nums[i] == recorder:
                counter += 1
            else:
                if counter > 2:
                    for j in range(counter - 2):
                        nums.pop(i - j - 1)
                    
                    i -= counter - 2

                recorder = nums[i]
                counter = 1

            i += 1

        #Consider last consecutive numbers
        if counter > 2:
            for j in range(counter - 2):
                print(i-j-1)
                nums.pop(i - j - 1)

        print(nums)

        return len(nums)

sol = Solution()
print(sol.removeDuplicates([1, 1, 1, 2, 2, 3]))
