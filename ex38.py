class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        ##Initialize a as the first item, while r as a blank string
        a = '1'
        r = ''

        #If n = 1, return 1
        if n == 1:
            return a

        #Loop to the specific n
        for i in range(0, n - 1):
            #Initialize n, num and counter
            n = 1
            num = a[0]
            counter = 1

            #Loop through the former number string
            while n < len(a):
                if a[n] == num:
                    counter += 1
                else:
                    r = r + str(counter) + num
                    num = a[n]
                    counter = 1
                
                n += 1

            #Add the last few numbers to the result string
            r = r + str(counter) + num
            
            #Restore a and r
            a = r
            r = ''
        
        return a

sol = Solution()
print(sol.countAndSay(5))