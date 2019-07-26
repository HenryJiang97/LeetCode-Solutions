class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """

        r = []

        #This function returns 1 if a and b needs to be swiped
        def compareTwoStr(a, b):
        	if int(a + b) < int(b + a):
        		return 1
        	else:
        		return 0


        #Convert the list of int to string
        s = [str(num) for num in nums]


        #Bubble sort
        j = len(s)

        for round in range(len(s) - 1):
        	minimum = s[0]

        	#Bubbling for each round
        	for i in range(1, j):
        		if compareTwoStr(minimum, s[i]) == 0:
        			minimum = s[i]

        	#Remove the minimum number from the list
        	s.remove(minimum)
        	j -= 1

        	#Add the tail number to the result list after each round
        	r.insert(0, minimum)
        

        #Insert the remaining num in the original list
        r.insert(0, s[0])

        #If the result is '00...', return a single 0
        if r[0] == '0':
        	return '0'
        else:
        	return ''.join(r)
        

sol = Solution()
print(sol.largestNumber([0, 0]))