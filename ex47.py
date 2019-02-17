import copy

class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        r = []
        nums.sort()

        #l-->list
        def recursion(self, l, store):
            #Judge a result
            if len(l) == 0:
                result = copy.deepcopy(store)
                r.append(result)
                return

            #Loop
            record = -9999
            for i in range(len(l)):
                if l[i] == record:
                    continue

                store.append(l[i])

                temp = copy.deepcopy(l)
                temp.pop(i)

                recursion(self, temp, store)

                store.pop(-1)

                record = l[i]

            return

        recursion(self, nums, [])

        return r


sol = Solution()
print(sol.permuteUnique([1, 1, 0, 0, 1, -1, -1, 1]))
       
