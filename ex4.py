class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        lst = nums1;
        lst.extend(nums2)
        lst.sort()

        if len(lst) % 2 != 0:
            return(float(lst[int((len(lst) + 1) / 2 - 1)]))
        else:
            return((lst[int(len(lst) / 2)] + lst[int(len(lst) / 2) - 1]) / 2)

sol = Solution()
print(sol.findMedianSortedArrays([1,2], [3]))