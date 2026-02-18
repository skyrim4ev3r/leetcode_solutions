class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        diff_to_len_map = {}
        count_zeros = 0
        count_ones = 0
        longest = 0

        diff_to_len_map[0] = 0

        for (i, num) in enumerate(nums):
            match num:
                case 1: count_ones += 1
                case 0: count_zeros += 1

            prev_len = diff_to_len_map.get(count_ones - count_zeros)

            if prev_len != None:
                longest = max(longest, i + 1 - prev_len)
            else:
                diff_to_len_map[count_ones - count_zeros] = i + 1

        return longest
