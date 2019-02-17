class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        r = [[]]

        for num in nums:
            for i in range(len(r)):
                r.append(r[i] + [num])

        return r


sol = Solution()
print(sol.subsets([1, 2, 3]))
