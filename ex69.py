class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if x == 0:
            return 0,
        
        left = 1
        right = 2 ** 31

        while left <= right:
            mid = (left + right) // 2

            if mid * mid > x:
                right = mid - 1
            else:
                if (mid + 1) * (mid + 1) > x:
                    return mid
                else:
                    left = mid + 1


sol = Solution()
print(sol.mySqrt(1158553694))
