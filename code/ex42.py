import copy

class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        if len(height) == 0:
            return 0

        r = 0

        #Pop zeros in the front and the end
        while height[0] == 0:
            height.pop(0)

            if len(height) == 0:
                return 0

        while height[-1] == 0:
            height.pop(-1)

            if len(height) == 0:
                return 0

        #Traverse from the left
        i = 0
        sign = 0
        summit = height.index(max(height))

        while i <= summit:
            maximum = height[i]

            l = []
            while height[i] <= maximum:
                l.append(maximum - height[i])

                #Decide if pointer reaches end
                if (i + 1) <= summit:
                    i += 1
                else:
                    sign = 1
                    break

            r += sum(copy.deepcopy(l))
            #If reaches the end, break the loop
            if sign != 0:
                break

        #Traverse from the right
        i = len(height) - 1
        sign = 0
        while i >= summit:
            maximum = height[i]

            l = []
            while height[i] <= maximum:
                l.append(maximum - height[i])

                #Decide if pointer reaches end
                if i - 1 >= summit:
                    i -= 1
                else:
                    sign = 1
                    break

            r += sum(copy.deepcopy(l))
            #If reaches the end, break the loop
            if sign != 0:
                break

        return r

sol = Solution()
print(sol.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
