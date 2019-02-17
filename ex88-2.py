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
            counter_1 = 0
            counter_2 = 0
            length = m

            while counter_2 < n:
                #If there is no items in nums1
                if counter_1 >= length:
                    nums1[counter_1] = nums2[counter_2]
                    counter_1 += 1
                    counter_2 += 1
                else:
                    #Compare items
                    if nums1[counter_1] <= nums2[counter_2]:
                        counter_1 += 1
                    else:
                        #Push items forward
                        for i in range(length - 1, counter_1 - 1, -1):
                            nums1[i + 1] = nums1[i]
                        nums1[counter_1] = nums2[counter_2]
                        length += 1
                
                        counter_2 += 1
                        counter_1 += 1

        return nums1

sol = Solution()
print(sol.merge([-1, 0, 0, 3, 3, 3, 0, 0, 0], 6, [1, 2, 2], 3))
