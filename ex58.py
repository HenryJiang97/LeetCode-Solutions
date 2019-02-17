class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        split = s.split(' ')

        while len(split) > 0:
            if split[-1] == '':
                split.pop(-1)
            else:
                break

        if len(split) == 0:
            return 0
        else:
            return len(split[-1])

sol = Solution()
print(sol.lengthOfLastWord(" a"))