class Solution:
    def canJump(self, nums: List[int]) -> bool:

        nums_len = len(nums)
        left = 0
        right = 0

        while right < nums_len - 1:
            max_jump = 0
            for i in range(left, right + 1):
                max_jump = max(max_jump, i + nums[i])

            if max_jump == right:
                return False

            left = right + 1
            right = max_jump

        return True
