class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        extra_num = nums2[-1]
        extra_num_min_cost = sys.maxsize
        total_cost = 0

        for i in range(n):
            min_val = min(nums1[i], nums2[i])
            max_val = max(nums1[i], nums2[i])
            total_cost += (max_val - min_val)

            if extra_num >= min_val and extra_num <= max_val:
                extra_num_min_cost = 0
            elif extra_num > max_val:
                extra_num_min_cost = min(extra_num_min_cost, extra_num - max_val)
            else:
                extra_num_min_cost = min(extra_num_min_cost, min_val - extra_num)

        return total_cost + 1 + extra_num_min_cost
