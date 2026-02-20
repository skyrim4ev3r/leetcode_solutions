MAX_VALID_BIT = 31

class Solution:
    def calc_lis_with_mask(self, nums: List[int], mask: int) -> int:
        sub: List[int] = []

        for num in nums:
            if (num & mask) == 0:
                continue

            pos = bisect.bisect_left(sub, num)
            if pos < len(sub):
                sub[pos] = num
            else:
                sub.append(num)

        return len(sub)

    def longestSubsequence(self, nums: List[int]) -> int:
        longest: int = 0

        for i in range(MAX_VALID_BIT):
            mask = 1 << i

            longest = max(longest, self.calc_lis_with_mask(nums, mask))

        return longest
