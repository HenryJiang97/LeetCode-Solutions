class Solution:
    def recursion(self, result, p, p_open, p_close):
        if p_open == 0 and p_close == 0:
            result.append(p)
            return

        if p_open > 0:
            self.recursion(result, p + '(', p_open - 1, p_close)

        if p_close > p_open:
            self.recursion(result, p + ')', p_open, p_close - 1)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        result = []

        self.recursion(result, '', n, n)

        return result
        

sol = Solution()
print(sol.generateParenthesis(3))