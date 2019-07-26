import copy
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        global r
        r = []
        
        #Create list
        a = []
        for i in range(n):
            a.append(i + 1)

        #l-->list
        def recursion(self, l, store):
            global r

            if len(store) == k:
                result = copy.deepcopy(store)
                r.append(result)
                return

            for i in range(len(l)):
                store.append(l[i])
            
                recursion(self, l[i + 1 : len(l) + 1], store)
                
                store.pop(-1)

            return

        recursion(self, a, [])

        return r

sol = Solution()
print(sol.combine(10, 7))
