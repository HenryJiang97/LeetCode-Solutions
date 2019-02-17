class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        
        # Special case: Blank list
        if nums == []:
            return []


        r = []

        i = 1
        start = 0
        while i < len(nums):
            if nums[i] == nums[i - 1] + 1:
                i += 1
            else:
                if i - start >=2:
                    # If numbers before are continuous
                    r.append(f"{nums[start]}->{nums[i - 1]}")
                else:
                    # If number before is not continuous
                    r.append(f"{nums[start]}")
                

                start = i
                i += 1


        # Add the last item to the result list
        if start == len(nums) - 1:
            r.append(f"{nums[start]}")
        else:
            r.append(f"{nums[start]}->{nums[i - 1]}")

        return r

sol = Solution()
print(sol.summaryRanges([]))