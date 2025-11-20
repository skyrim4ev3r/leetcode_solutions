class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        longest = 1
        curr = 0
        n = len(nums)
        state = 0

        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                if state != 1:
                    curr = 2
                    state = 1
                else:
                    curr += 1
            elif nums[i] < nums[i - 1]:
                if state != -1:
                    curr = 2
                    state = -1
                else:
                    curr += 1
            else:
                state = 0
                curr = 1

            longest = max(longest, curr)

        return longest
