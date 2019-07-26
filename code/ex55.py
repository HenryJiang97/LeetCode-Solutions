class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        if len(nums) == 1:
            return True
        elif nums[0] == 0:
            return False


        for i in range(len(nums)):
            if nums[i] == 0:
                #When i points to the last item in the list which is 0
                if i == len(nums) - 1:
                    break

                recap = 0
                #Recap
                j = i - 1
                while j >= 0:
                    if (nums[j] <= (i - j)):
                        recap += 1

                    j -= 1

                #If there is no valid jump to transcend 0, return false
                if recap == i:
                    return False

        return True


sol = Solution()
print(sol.canJump([2,0,0]))
