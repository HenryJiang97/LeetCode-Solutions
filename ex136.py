class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        storage = {}

        for num in nums:
            if not storage.__contains__(str(num)):
                storage.update({str(num) : 1})
            else:
                storage[str(num)] += 1

        for k, v in storage.items():
            if v == 1:
                return int(k)


sol = Solution()
print(sol.singleNumber([4,1,2,1,2]))