class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
        if needle == '':
            return 0
        else:
            return haystack.find(needle)
   

sol = Solution()
print(sol.strStr("hello", "llv"))