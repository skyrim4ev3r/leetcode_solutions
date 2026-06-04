class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prev_max = 1
        prev_min = 1
        max_prod = -sys.maxsize - 1

        for num in nums:
            curr_min = min(num, num * prev_min, num * prev_max)
            curr_max = max(num, num * prev_min, num * prev_max)

            max_prod = max(max_prod, curr_max)
            prev_max = curr_max
            prev_min = curr_min

        return max_prod
