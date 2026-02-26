class Solution:
    def maximumPossibleSize(self, nums: List[int]) -> int:
        total_count = len(nums)
        curr_max = -sys.maxsize - 1
        remove_count = 0

        for num in nums:
            curr_max = max(curr_max, num)

            if num < curr_max:
                remove_count += 1

        return total_count - remove_count
