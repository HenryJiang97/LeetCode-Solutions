class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if (len(s) < len(p)):
            return False

        i = 0
        j = 0

        while (i < len(s)) & (j < len(p)):
            if s[i] == p[j]:
                i += 1
                j += 1
            elif p[j] == '?':
                i += 1
                j += 1
            elif p[j] == '*':
                if (j + 1) == len(p):
                    return True

                j += 1
                i += 1

                if p[j] == '*':
                    while p[j] == '*':
                        j += 1
                        i += 1

                if p[j] == '?':
                    i += 1
                    continue

                while (s[i] != p[j]):
                    i += 1
                
                if (s[i] == p[j]):
                    i += 1
                    j += 1
            else:
                return False

        if (i < len(s)) | (j < len(p)):
            return False
        
        return True
        

sol = Solution()
print(sol.isMatch('abbbb', '?*b**'))