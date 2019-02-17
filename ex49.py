class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        r = []

        dic = {}
        for i in range(len(strs)):
            #Sort each string with alphabet order
            a = list(strs[i])
            a.sort()
            a = ''.join(a)

            #Add strings to dic in categories
            if a not in dic:
                dic.update({a : []})
                dic.get(a).append(strs[i])
            else:
                dic.get(a).append(strs[i])

        for key, value in dic.items():
            r.append(value)

        return r
        

sol = Solution()
print(sol.groupAnagrams(["aa","aa"]))