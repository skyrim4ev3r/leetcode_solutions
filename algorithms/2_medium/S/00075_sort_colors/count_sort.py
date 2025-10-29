class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        colors_len = 3
        colors_count = [0] * colors_len

        for num in nums:
            colors_count[num] += 1

        nums_index = 0
        for i in range(colors_len):
            for _ in range(colors_count[i]):
                nums[nums_index] = i
                nums_index += 1
