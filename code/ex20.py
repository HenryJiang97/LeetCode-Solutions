class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        open_bracket = ['(', '{', '[']
        close_bracket = [')', '}', ']']
        pairs = {'(':')', '{':'}', '[':']'}

        stack = []
        for i in s:
            if i in open_bracket:
                stack.append(i)
                continue

            if (i in close_bracket) & (stack != []):
                if i == pairs.get(stack.pop(-1)):
                    continue
                else:
                    return False
            else:
                return False

        if stack == []:
            return True
        else:
            return False


sol = Solution()
print(sol.isValid('()'))