class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        
        if rowIndex == 0:
            return [1]
        
        if rowIndex == 1:
            return [1, 1]


        res = [[1], [1, 1]]
        
        for i in range(2, rowIndex + 1):
            res.append([])

            for j in range(i + 1):
                if j == 0 or j == i:
                    res[i].append(1)
                else:
                    res[i].append(res[i - 1][j - 1] + res[i - 1][j])

        return res[rowIndex]
        