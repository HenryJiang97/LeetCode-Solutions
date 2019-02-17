class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        
        record = {}
        minimum = 2 ** 31


        for i in range(len(nums)):
            if nums[i] not in record:
                record.update({nums[i]:i})
            else:
                if i - record[nums[i]] < minimum:
                    minimum = i - record[nums[i]]

                if minimum <= k:
                    return True

                record[nums[i]] = i

                
        return False


sol = Solution()
print(sol.containsNearbyDuplicate([1,2,3,1], 3))