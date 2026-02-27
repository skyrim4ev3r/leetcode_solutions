class Solution:
    def is_valid(self, nums: List[int], max_valid_sum: int, k: int) -> bool:
        curr_sum = 0
        count = 0

        for num in nums:
            if curr_sum + num <= max_valid_sum:
                curr_sum += num
            else:
                curr_sum = num
                count += 1

                if count == k:
                    return False

        return True

    def splitArray(self, nums: List[int], k: int) -> int:
        high = sum(nums)
        low = max(nums)

        while low <= high:
            mid = low + (high - low) // 2

            match self.is_valid(nums, mid, k):
                case True: high = mid - 1
                case False: low = mid + 1

        return low
