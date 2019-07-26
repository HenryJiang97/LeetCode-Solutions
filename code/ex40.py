import copy

class Solution:
    def dfs(self, candidates, target, l, remain, start):
        global r

        if remain < 0:
            return

        if remain == 0:
            a = copy.deepcopy(l)
            if a not in r:
                r.append(a)

        for i in range(start, len(candidates)):
            l.append(candidates[i])
            self.dfs(candidates, target, l, remain - candidates[i], i + 1)
            l.pop(-1)

    
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        global r
        r = []

        candidates.sort()

        self.dfs(candidates, target, [], target, 0)

        return r
        

sol = Solution()
print(sol.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
