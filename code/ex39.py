import copy

class Solution:
    def dfs(self, candidates, target, l, remain, start):
        global r

        if remain < 0:
            return

        if remain == 0:
            a = copy.deepcopy(l)
            r.append(a)

        for i in range(start, len(candidates)):
            l.append(candidates[i])
            self.dfs(candidates, target, l, remain - candidates[i], i)
            l.pop(-1)

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """    
        
        global r
        r = []

        self.dfs(candidates, target, [], target, 0)

        return r

sol = Solution()
print(sol.combinationSum([2,3,5], 8))
