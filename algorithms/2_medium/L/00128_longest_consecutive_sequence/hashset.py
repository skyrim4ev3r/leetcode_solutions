class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniques = set(nums)
        max_len = 0

        for num in uniques:
            if num - 1 not in uniques:
                right = num

                while right + 1 in uniques:
                    right += 1

                max_len = max(max_len, right - num + 1)

        return max_len
