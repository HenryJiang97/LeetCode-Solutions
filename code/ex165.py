class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """

        s1 = version1.split('.')
        s2 = version2.split('.')

        length = min(len(s1), len(s2))

        #Compare the head part
        for i in range(length):
            if int(s1[i]) > int(s2[i]):
                return 1
            
            if int(s1[i]) < int(s2[i]):
                return -1


        #Compare later part of the longer version number
        if len(s1) > len(s2):
            #If all version number in the end is 0.0.0..., two version is the same, else the longer one is larger
            for num in s1[len(s2) : ]:
                if int(num) != 0:   return 1
            return 0
        elif len(s1) < len(s2):
            #If all version number in the end is 0.0.0..., two version is the same, else the longer one is larger
            for num in s2[len(s1) : ]:
                if int(num) != 0:   return -1
            return 0
        else:
            return 0   

sol = Solution()
print(sol.compareVersion('1.1', '1.01.0'))
