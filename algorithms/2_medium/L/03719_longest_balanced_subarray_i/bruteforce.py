class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        longest = 0

        for i in range(n):
            evens= set()
            odds = set()

            for j in range(i, n):
                if (nums[j] & 1) == 0:
                    odds.add(nums[j])
                else:
                    evens.add(nums[j])

                if len(odds) == len(evens):
                    longest = max(longest, j - i + 1)

        return longest
