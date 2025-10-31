class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        nums.sort()

        nums_len = len(nums)
        half = nums_len // 2
        count = 1

        for i in range(1, nums_len):
            if nums[i-1] == nums[i]:
                count += 1
            else:
                count = 1

            if count > half:
                return nums[i]

        return nums[0]
