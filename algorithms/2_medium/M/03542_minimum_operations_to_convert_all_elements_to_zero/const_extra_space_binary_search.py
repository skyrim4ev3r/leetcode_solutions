class Solution:
    def minOperations(self, nums: List[int]) -> int:
        curr_stack_len = 0
        count = 0
        nums_len = len(nums)

        def custom_bisect_left(arr, num, end):
            left, right = 0, end
            while left < right:
                mid = (left + right) // 2
                if arr[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            return left

        for i in range(nums_len):
            num = nums[i]

            if num == 0:
                count += curr_stack_len
                curr_stack_len = 0
            else:
                pos = custom_bisect_left(nums, num, curr_stack_len)

                if pos == curr_stack_len:
                    nums[pos] = num
                    curr_stack_len += 1
                else:
                    if nums[pos] == num:
                        count += curr_stack_len - pos - 1
                    else:
                        nums[pos] = num;
                        count += curr_stack_len - pos

                    curr_stack_len = pos + 1

        return count + curr_stack_len 
