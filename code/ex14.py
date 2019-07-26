class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        #If there is no items in the list, return ''. If only one item in the list, return that item
        if len(strs) == 0:
            return ''
        elif len(strs) == 1:
            return strs[0]

        #Calculate the minimum length of items in the list
        min_len = len(strs[0])

        i = 1
        while i < len(strs):
            if len(strs[i]) < min_len:
                min_len = len(strs[i])
            
            i += 1

        #If there are blank item in the list, return ''
        if min_len == 0:
            return ''

        #Find out the maximum prefix
        for i in range(0, min_len):
            char = strs[0][i]

            for j in range(1, len(strs)):
                if char != strs[j][i]:
                    if i != 0:
                        return strs[0][0:i:1]
                    else:
                        return ''

        #If the prefix is the same as the shortest item, return the shortest item
        if i == min_len - 1:
            return strs[0][0:min_len:1]          


sol = Solution()
print(sol.longestCommonPrefix(["abab","aba",""]))