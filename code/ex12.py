class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        #>=1000
        if num >= 1000:
            m = 'M' * (num // 1000)
        else:
            m = ''

        num = num % 1000

        #500-1000
        if num >= 500:
            if num >= 900:
                d = 'CM'
                num = num % 900
            else:
                d = 'D' * (num // 500)
                num = num % 500        
        else:
            d = ''      

        #100-500
        if num >= 100:
            if num >= 400:
                c = 'CD'
                num = num % 400
            else:
                c = 'C' * (num // 100)
                num = num % 100
        else:
            c = ''


        #50-100
        if num >= 50:
            if num >= 90:
                l = 'XC'
                num = num % 90
            else:
                l = 'L' * (num // 50)
                num = num % 50
        else:
            l = ''    


        #10-50
        if num >= 10:
            if num >= 40:
                x = 'XL'
                num = num % 40
            else:
                x = 'X' * (num // 10)
                num = num % 10
        else:
            x = ''
       

        #5-10
        if num >= 5:
            if num >= 9:
                v = 'IX'
                num = num % 9
            else:
                v = 'V' * (num // 5)
                num = num % 5
        else:
            v = ''
        

        if num == 4:
            i = 'IV'
        else:
            i = 'I' * num       

        return m + d + c + l + x + v + i

sol = Solution()
print(sol.intToRoman(20))