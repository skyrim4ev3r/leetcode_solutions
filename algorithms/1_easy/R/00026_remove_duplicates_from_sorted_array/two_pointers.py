class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        nums_len = len(nums)
        write_index = 1

        for read_index in range(1, nums_len):
            if nums[read_index] != nums[read_index - 1]:
                nums[write_index] = nums[read_index]
                write_index += 1

        return write_index
