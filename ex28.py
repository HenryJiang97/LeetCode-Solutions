class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
        if needle == '':
            return 0
        
        if haystack == '':
            return -1

        i = 0
        j = 0

        while i < len(haystack):            
            if haystack[i] == needle[j]:
                #Record the first place
                record = i

                i += 1
                j += 1
                
                #Loop through needle to compare with str in haystack
                while j < len(needle):
                    #If needle is longer than haystack, return -1
                    if i >= len(haystack):
                        return -1

                    #Break the loop when needle is different from the str in haystack
                    if haystack[i] != needle[j]:
                        break

                    i += 1
                    j += 1
                    
                #If the needle is found in haystack, return the head position
                if j == len(needle):
                    return record
                else:
                    i = record + 1
                    j = 0
            else:
                i += 1
  
        return -1
   

sol = Solution()
print(sol.strStr("", ""))