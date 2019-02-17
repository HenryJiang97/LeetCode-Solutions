class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """

        if n != 0:
            j = 0
            for i in range(3, m + n):
                nums1[i] = nums2[j]
                j += 1

            nums1.sort()
            
            return nums1

sol = Solution()
print(sol.merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3))
