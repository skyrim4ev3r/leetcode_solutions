class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        for i in range(n):
            if nums[i] <= 0:
                nums[i] = sys.maxsize

        for i in range(n):
            num = abs(nums[i]) - 1
            if num < n:
                if nums[num] > 0:
                    nums[num] *= -1

        for i in range(n):
            if nums[i] > 0:
                return i + 1

        return n + 1
