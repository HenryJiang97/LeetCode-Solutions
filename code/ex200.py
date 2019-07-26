class Solution:
	def recursion(self, grid, record, i, j, sign):
		record[i][j] = 1;
		#print(record)

		if sign != 'lower':
			if (i + 1) < len(grid):
				if grid[i + 1][j] != '0':
					if record[i + 1][j] == 0:
						self.recursion(grid, record, i + 1, j, 'upper')

		if sign != 'right':
			if (j + 1) < len(grid[0]):
				if grid[i][j + 1] != '0':
					if record[i][j + 1] == 0:
						self.recursion(grid, record, i, j + 1, 'left')
		
		if sign != 'upper':
			if (i - 1) >= 0:ø
				if grid[i - 1][j] != '0':
					if record[i - 1][j] == 0:
						self.recursion(grid, record, i - 1, j, 'lower')

		if sign != 'left':
			if (j - 1) >= 0:
				if grid[i][j - 1] != '0':
					if record[i][j - 1] == 0:
						self.recursion(grid, record, i, j - 1, 'right')



	def numIslands(self, grid):
		"""
		:type grid: List[List[str]]
		:rtype: int
		"""

		# Create a 2n blank list
		record = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]

		#Init
		i = 0
		j = 0
		count = 0

		for i in range(len(grid)):
			for j in range(len(grid[0])):
				if (grid[i][j] == '1') and (record[i][j] == 0):
					record[i][j] = 1

					if (i + 1) < len(grid):
						if grid[i + 1][j] != '0':
							self.recursion(grid, record, i + 1, j, 'upper')

					if (j + 1) < len(grid[0]):
						if grid[i][j + 1] != '0':
							self.recursion(grid, record, i, j + 1, 'left')

					if (i - 1) >= 0:
						if grid[i - 1][j] != '0':
							self.recursion(grid, record, i - 1, j, 'lower')

					if (j - 1) >= 0:
						if grid[i][j - 1] != '0':
							self.recursion(grid, record, i, j - 1, 'right')


					#  print(record)
					count += 1


		return count


sol = Solution()
print(sol.numIslands([["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]))