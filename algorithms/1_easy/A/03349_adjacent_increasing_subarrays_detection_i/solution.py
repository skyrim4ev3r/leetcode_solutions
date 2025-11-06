class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:

        left = 0
        right = (2 * k) - 1
        nums_len = len(nums)

        while right < nums_len:
            is_increasing = True

            for i in range(left + 1, right + 1):
                if i == left + k:
                    continue

                if nums[i - 1] >= nums[i]:
                    is_increasing = False
                    break

            if is_increasing:
                return True

            left += 1
            right += 1

        return False
