class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)
        sorted_nums = nums.copy()

        sorted_nums.sort()

        counts = {}

        for i in range(nums_len):
            if i > 0 and sorted_nums[i] == sorted_nums[i - 1]:
                    continue

            counts[sorted_nums[i]] = i

        res = []

        for num in nums:
            res.append(counts[num])

        return res
