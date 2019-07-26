class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        d = {}
        maximum = 0

        for num in nums:
            if str(num) not in d:
                d.update({str(num): 1})
            else:
                d[str(num)] += 1

        for k, v in d.items():
            if v > maximum:
                maximum = v
                r = k

        return int(r)

sol = Solution()
print(sol.majorityElement([2, 2, 1, 1, 1, 2, 2]))
