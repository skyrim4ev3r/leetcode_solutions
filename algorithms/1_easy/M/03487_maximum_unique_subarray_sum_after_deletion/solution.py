class Solution:
    def maxSum(self, nums: List[int]) -> int:
        nums_set = set()
        max_val = -100000000000000

        for num in nums:
            if num > 0:
                nums_set.add(num)
            max_val = max(num, max_val)

        if not nums_set:
            return max_val

        return sum(nums_set)
