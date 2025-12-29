class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        def find_dominant(nums: List[int]) -> int:
            curr_freq = 0
            curr_num = 0

            for num in nums:
                if curr_freq == 0:
                    curr_num = num
                    curr_freq = 1
                else:
                    if num != curr_num:
                        curr_freq -= 1
                    else:
                        curr_freq += 1

            return curr_num

        n = len(nums)
        dominant = find_dominant(nums)
        right_count_dominant = nums.count(dominant)
        left_count_dominant = 0

        for (i, num) in enumerate(nums):
            if num == dominant:
                right_count_dominant -= 1
                left_count_dominant += 1

            if left_count_dominant > (i + 1) // 2 and right_count_dominant > (n - i - 1) // 2:
                return i

        return -1
