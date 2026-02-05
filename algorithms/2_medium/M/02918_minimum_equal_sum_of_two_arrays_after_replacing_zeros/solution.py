class Solution:
    def calc_sum_and_zeros(self, nums: List[int]) -> (int, int):
        total_sum = 0
        zeros = 0

        for num in nums:
            total_sum += num

            if num == 0:
                zeros += 1

        return (total_sum, zeros)

    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        (sum1, zeros1) = self.calc_sum_and_zeros(nums1)
        (sum2, zeros2) = self.calc_sum_and_zeros(nums2)
        min_valid_sum1 = sum1 + zeros1
        min_valid_sum2 = sum2 + zeros2

        if (zeros1 == 0 and sum1 < min_valid_sum2) or (zeros2 == 0 and min_valid_sum1 > sum2):
            return -1

        return max(min_valid_sum1, min_valid_sum2)
