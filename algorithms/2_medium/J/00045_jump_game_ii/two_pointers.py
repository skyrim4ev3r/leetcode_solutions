class Solution:
    def jump(self, nums: List[int]) -> int:

        nums_len = len(nums)
        left = 0
        right = 0
        count = 0

        while right < nums_len - 1:
            max_jump = 0

            for i in range(left, right + 1):
                max_jump = max(max_jump, i + nums[i])
            left = right + 1
            right = max_jump
            count += 1

        return count
