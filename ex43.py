class Solution:
    def convertion(self, num):
            i = 0
            n = 0

            while i < len(num):
                n += int(num[i]) * (10**(len(num) - i - 1))
            
                i += 1

            return n

    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """       

        n1 = self.convertion(num1)
        n2 = self.convertion(num2)

        return str(n1 * n2)


sol = Solution()
print(sol.multiply('123', '456'))