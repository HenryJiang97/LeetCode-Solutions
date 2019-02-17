class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        nums.sort()

        r = [[]]

        for num in nums:
            for i in range(len(r)):
                #Remove duplicate items
                if (r[i] + [num]) not in r:
                    r.append(r[i] + [num])

        return r

sol = Solution()
print(sol.subsetsWithDup([4,4,4,1,4]))
