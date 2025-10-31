class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        nums_len = len(nums)
        write_index = 0

        for read_index in range(nums_len):
            if nums[read_index] != 0:
                nums[write_index] = nums[read_index]
                write_index += 1

        for i in range(write_index, nums_len):
            nums[i] = 0
