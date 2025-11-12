class Solution:
    def minOperations(self, nums: List[int]) -> int:
        nums_len = len(nums)
        all_gcd = 0
        count_ones = 0

        for num in nums:
            if num == 1:
                count_ones += 1

            all_gcd = gcd(all_gcd, num)

        if all_gcd != 1:
            return -1

        if count_ones > 0:
            return nums_len - count_ones

        min_len = sys.maxsize

        for i in range(nums_len):
            if min_len == 2:
                break

            curr_gcd = 0

            for j in range(i, nums_len):
                curr_gcd = gcd(curr_gcd, nums[j])

                if curr_gcd == 1:
                    min_len = j - i + 1
                    break

        op_need_to_make_one_x_one = min_len - 1
        op_need_after_it = nums_len - 1

        return op_need_to_make_one_x_one + op_need_after_it
