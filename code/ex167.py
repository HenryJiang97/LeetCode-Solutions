class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """

        #Do the first number
        if (target - numbers[0]) in numbers[1:]:
                return [1, numbers[1:].index(target - numbers[0]) + 2]


        for i in range(1, len(numbers)):
            #Skip duplicated numbers
            if numbers[i] == numbers[i - 1]:
                continue

            #Search for the second index
            if (target - numbers[i]) in numbers[i + 1 : ]:
                return [i + 1, numbers[i + 1 : ].index(target - numbers[i]) + i + 2]

sol = Solution()
print(sol.twoSum([0, 0, 11, 15], 0))
