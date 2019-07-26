# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """

        if intervals == []:
            return []

        #Sort the list according to the start value
        inter = sorted(intervals, key=lambda x: x[0])

        r = []

        temp = inter[0]
        for i in range(len(inter) - 1):
            if temp[1] >= inter[i + 1][0]:
                temp = [temp[0], max(temp[1], inter[i + 1][1])]
            else:
                r.append(temp)
                temp = inter[i + 1]

        r.append(temp)
        return r

sol = Solution()
print(sol.merge([[1,10], [2,3], [4,5], [6,7], [8,9]]))
