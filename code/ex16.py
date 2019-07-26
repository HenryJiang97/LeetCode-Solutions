class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        length = len(nums)
        minimum = 2 **31

        for i in range(0, length - 2):
            for j in range(i + 1, length - 1):
                for k in range(j + 1, length):
                    print(nums[i], nums[j], nums[k])
                    gap = abs(nums[i] + nums[j] + nums[k] - target)

                    if gap < minimum:
                        minimum = abs(nums[i] + nums[j] + nums[k] - target)
                        r = nums[i] + nums[j] + nums[k]


        return r

sol = Solution()
print(sol.threeSumClosest([1, 1, -1, -1, 3],
                          3))
