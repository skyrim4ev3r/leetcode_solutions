class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1: return n

        cnt = 1
        direction = 0

        for i in range(1, n):
            if nums[i] > nums[i - 1] and direction != 1:
                direction = 1
                cnt += 1

            if nums[i] < nums[i - 1] and direction != -1:
                direction = -1
                cnt += 1

        return cnt
