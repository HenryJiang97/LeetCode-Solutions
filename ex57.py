# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
        if intervals == []:
            inter = [newInterval]
        else:
            #Sort the list according to the start value
            inter = sorted(intervals, key=lambda x: x[0])
        
            #Insert newInterval
            a = 0

            while (newInterval[0] > inter[a][0]):
                a += 1
                if a >= len(inter):
                    break
            inter.insert(a, newInterval)

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
print(sol.insert([[1, 3], [6, 9]], [2, 5]))

    
