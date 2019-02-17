class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        str_x = str(x)

        if str_x[::1] == str_x[::-1]:
            return True
        else:
            return False

sol = Solution()
print(sol.isPalindrome(123))