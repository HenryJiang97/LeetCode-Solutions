class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if(x >= 0):
            string = str(x)
            re_string = string[::-1]

            result = int(re_string)

            if result <= 2**31 - 1:
                return result
            else:
                return 0
        else:
            string = str(-x)
            re_string = string[::-1]

            result = -int(re_string)
            
            if result >= -2**31:
                return result
            else:
                return 0

sol = Solution()
print(sol.reverse(-1534236469))