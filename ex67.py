class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        r = ''

        la = list(str(a))
        lb = list(str(b))

        #Keep two binaries at the same length
        if len(la) > len(lb):
            for i in range(len(la) - len(lb)):
                lb.insert(0, '0')
        elif len(lb) > len(la):
            for i in range(len(lb) - len(la)):
                la.insert(0, '0')

        #Add
        cache = 0

        for i in range(len(la) - 1, -1, -1):
            s = int(la[i]) + int(lb[i])

            if s + cache == 0:
                r = '0' + r
                cache = 0
            elif s + cache == 1:
                r = '1' + r
                cache = 0
            elif s + cache == 2:
                r = '0' + r
                cache = 1
            elif s + cache == 3:
                r = '1' + r
                cache = 1

        #If cache is left, add 1 to the front
        if cache == 1:
            r = '1' + r

        return r


sol = Solution()
print(sol.addBinary(1010, 1011))
