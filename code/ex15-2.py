class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        List = []

        if len(nums) < 3:
            return []
        else:
            nums.sort()
            for k in range(len(nums) - 2):
                if nums[k] > 0:
                    break
                else:
                    i = k + 1
                    j = len(nums) - 1
                    while (i < j) and (nums[j] >= 0):
                        if nums[k] + nums[i] + nums[j] == 0:
                            List.append([nums[k], nums[i], nums[j]])

                            i += 1
                            j -= 1

                            #Skip the duplicated numbers
                            if nums[i] == nums[i - 1]:
                                i += 1

                            if nums[j] == nums[j + 1]:
                                j -= 1
                        
                        elif nums[k] + nums[i] + nums[j] < 0:
                            i += 1
                        elif nums[k] + nums[i] + nums[j] > 0:
                            j -= 1

        for l in List:
            tuple(l)

        return list(set([tuple(t) for t in List]))

sol = Solution()
print(sol.threeSum([-1, 0, 1, 2, -1, -4]))
