#Three steps: 
# Step 1: 从后向前寻找第一个降序数字，记为index
# Step 2: 从后向前寻找一个略大于index的数，将它们交换
# Step 3: 将index之后的数倒序排序

class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        i = len(nums) - 2

        #Find the index where the number suddenly becomes smaller
        while i >= 0:
            if nums[i] < nums[i + 1]:
                index = i
                break

            i -= 1

        #If the list is in entirely decending order
        if i == -1:
            nums.reverse()

            return nums
        else:

            #Search for a number from the end which is slightly larger than nums[]
            i = len(nums) - 1
            while i >= index:
                if nums[i] > nums[index]:
                    temp = nums[i]
                    nums[i] = nums[index]
                    nums[index] = temp

                    break

                i -= 1

            #Reverse the list behind index
            i = index + 1
            j = len(nums) - 1

            while i < j:
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp

                i += 1
                j -= 1


            return nums

sol = Solution()
print(sol.nextPermutation([3,4,1]))