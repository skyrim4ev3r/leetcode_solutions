class Solution:
    def minOperations(self, nums: List[int]) -> int:
        curr_stack_len = 0
        count = 0
        nums_len = len(nums)

        for i in range(nums_len):
            num = nums[i]

            if num == 0:
                count += curr_stack_len
                curr_stack_len = 0
            else:
                while curr_stack_len > 0 and nums[curr_stack_len - 1] > num:
                    count += 1
                    curr_stack_len -= 1

                if curr_stack_len > 0 and nums[curr_stack_len - 1] == num:
                    continue

                nums[curr_stack_len] = num
                curr_stack_len += 1

        return count + curr_stack_len
