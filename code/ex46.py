import copy

class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        r = []

        #l-->list
        def recursion(self, l, store):
            #Judge a result
            if len(l) == 0:
                result = copy.deepcopy(store)
                r.append(result)
                return

            #Loop
            for i in range(len(l)):
                store.append(l[i])

                temp = copy.deepcopy(l)
                temp.pop(i)

                recursion(self, temp, store)

                store.pop(-1)

            return

        recursion(self, nums, [])

        return r


sol = Solution()
print(sol.permute([1, 2, 3, 4]))
