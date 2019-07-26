class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        items = list(str)
        
        #Return 0 when input is ''
        if len(items) == 0:
            return 0

        #Delete spaces in the front
        while (len(items) > 0):
            if items[0] == ' ':
                items.pop(0)
            else:
                break

        
        #If the string only has spaces, return 0
        if len(items) == 0:
            return 0
        
        #Record the plus and minus sign
        sign = ' '

        if items[0] == '-':
            sign = '-'
            items.pop(0)
        elif items[0] == '+':
            items.pop(0)

        #See if the string only has plus and minus sign
        if len(items) == 0:
            return 0

        #If the first character besides space and '+', '-' is not a number, return 0
        if not (ord(items[0]) >= 48) & (ord(items[0]) <= (48 + 9)):
            return 0

        
        #Append numbers into a new list called result  
        result = int(items[0])
        i = 1

        while i < len(items):
            if (ord(items[i]) >= 48) & (ord(items[i]) <= (48 + 9)):
                result = result * 10 + int(items[i])
                i += 1
            else:
                break


        #Add + and - sign to the result
        if sign == '-':
            result = -result


        #If the result is beyond range, return the maximum or minimum number of 32-bit integer
        if result > 2**31 - 1:
            return 2**31 - 1
        elif result < -2**31:
            return -2**31

        return result


sol = Solution()
print(sol.myAtoi('-2'))