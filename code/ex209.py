class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        
        # If no available minimal length exist, return 0
        if sum(nums) < s:
            return 0

        # Initiate two pointers: head, end
        head = 0
        end = 0

        # Find the first possible length of subarray which sum >= s
        val = 0
        while (end < len(nums)) & (val < s):
            val += nums[end]

            end += 1


        minimum = end - head


        # Find if there's shorter subarrays existing
        end -= 1
        val -= nums[end]

        while end < len(nums):
            val += nums[end]

            if val >= s:
                while val >= s:
                    head += 1
                    # print(head,end)
                    val -= nums[head - 1]

                if (end - head + 2) < minimum:
                    minimum = end - head + 2
                
                # print(minimum)


            # If the available length falls to 1, then 1 is the minimum length
            if minimum == 1:
                return 1

            end += 1



        return minimum
            
                
            
sol = Solution()
print(sol.minSubArrayLen(7, [2,3,1,2,4,3]))