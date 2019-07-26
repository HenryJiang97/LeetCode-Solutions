class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        

        # r for result; dic for a dictionary to record numbers of elements in the list
        r = []
        dic = {}

        for i in nums:
            if i not in dic:
                dic.update({i:1})
            else:
                dic[i] += 1
                

        if dic != {}:
            for k, v in dic.items():
                if v > int(len(nums) / 3):
                    r.append(k)


        return r


sol = Solution()
print(sol.majorityElement([]))