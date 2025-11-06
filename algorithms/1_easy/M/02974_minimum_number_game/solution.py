class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)

        nums.sort()

        for i in range(0, nums_len - 1, 2):
            tmp = nums[i + 1]
            nums[i + 1] = nums[i]
            nums[i] = tmp

        return nums
