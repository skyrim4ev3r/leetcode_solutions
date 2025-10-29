class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums_len = len(nums)

        if nums_len < 3:
            return nums_len

        write_index = 2

        for read_index in range(2, nums_len):
            if nums[read_index] == nums[write_index - 2]:
                continue

            nums[write_index] = nums[read_index]
            write_index += 1

        return write_index
