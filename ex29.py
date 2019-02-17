class Solution:   
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        # if (dividend < -2**30) | (dividend > 2**30 - 1):
        #     #When divident = 0, return 0
        #     if abs(dividend) < abs(divisor):
        #         return 0

        #     result = abs(dividend) // abs(divisor)

        #     ##Adding + and -
        #     if not((dividend > 0) & (divisor > 0)) | ((dividend < 0) & (divisor < 0)):
        #         result = -result

        #     #If the result exceed the limitation, return 2**31 - 1
        #     if (result >= -2**31) & (result <= 2**31 - 1):
        #         return result
        #     else:    
        #         return 2**31 - 1
                
        
        #When divident = 0, return 0
        if abs(dividend) < abs(divisor):
            return 0

        a = abs(dividend)
        b = abs(divisor)
        b_backup = b
        count = 0
        t = 0

        
        while a >= b:
            b = b << 1
            t += 1

        count = 2 ** (t - 1)
        b = b >> 1
        
        #Recursion
        if a - b >= b_backup:
            count += self.divide(a - b, b_backup)

        ##Adding + and -
        if not((dividend > 0) & (divisor > 0)) | ((dividend < 0) & (divisor < 0)):
            count = -count
        

        #If the result exceed the limitation, return 2**31 - 1
        if count == 2**31:
            return 2**31 - 1
        else:
            return count

sol = Solution()
print(sol.divide(10,3))