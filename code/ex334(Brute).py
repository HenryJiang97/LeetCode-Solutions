class Solution:
    def increasingTriplet(self, nums: 'List[int]') -> 'bool':
        if (len(nums) == 0):    return False
        
        # Init the dp array and set all position to 1
        dp = [1 for i in range(0, len(nums))]
        
        # Traverse the list and build dp array
        for i in range(1, len(nums)):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    
            if dp[i] >= 3: return True
            
        
        return False


sol = Solution()
print(sol.increasingTriplet([10,9,2,5,3,7,101,18]))