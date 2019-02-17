class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        max_area = 0       
        head = 0
        rear = len(height) - 1


        while rear - head >= 1:
            if (rear - head) * min(height[head], height[rear]) > max_area:
                max_area = (rear - head) * min(height[head], height[rear])


            if height[head] > height[rear]:
                rear -= 1
            else:
                head += 1
        
            
        return max_area


sol = Solution()
print(sol.maxArea([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))