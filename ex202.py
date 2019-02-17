class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """


        # Store the appeared value
        visited = []


        # Loop while the result is not 1 and not in the visited list
        while (n not in visited) & (n != 1):
        	# Add result into visited list
        	visited.append(n)

        	t = n
        	n = 0

        	# Loop to get the square of each digit
        	while t > 0:
        		n += (t % 10) ** 2
        		t = t // 10
        	

        # Return
        if n == 1:
        	return True
        else:
        	return False



sol = Solution()
print(sol.isHappy(19))