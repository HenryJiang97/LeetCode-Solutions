class Solution:
	def rangeBitwiseAnd(self, m, n):
		"""
        :type m: int
        :type n: int
        :rtype: int
        """

		r = 0
		d = 0

		while n != 0:
			if ((n - m) == 0) and ((n % 2) == 1):
				r += 2 ** d

			# Cut the last bit off from m, n
			if (m % 2) == 1:
				m -= 1
			if (n % 2) == 1:
				n -= 1

			m /= 2
			n /= 2

			# Increase the degree
			d += 1


		return r


sol = Solution()
print(sol.rangeBitwiseAnd(0, 1))