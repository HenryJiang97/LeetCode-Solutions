import copy

class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        r = copy.deepcopy(digits)

        i = -1

        if r[i] != 9:
            r[i] += 1
            return r
        else:
            while i >= -len(digits):
                if r[i] == 9:
                    r[i] = 0
                    i -= 1
                else:
                    r[i] += 1
                    i -= 1
                    break

        if r[0] == 0:
            r.insert(0, 1)

        return r

sol = Solution()
print(sol.plusOne([9,9,9]))