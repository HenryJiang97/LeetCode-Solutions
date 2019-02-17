class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        r = 0
        i = 0
        result = []
        dic = {}

        while i < len(s):
            if s[i] not in result:
                result.append(s[i])
                dic.update({s[i] : i})
                count += 1
                i += 1

            else:
                if count > r:
                    r = count

                i = dic.get(s[i]) + 1
                                   
                result.clear()
                count = 0

        if count > r:
            r = count

        return r


s = Solution()
print(s.lengthOfLongestSubstring('dvdf'))
  