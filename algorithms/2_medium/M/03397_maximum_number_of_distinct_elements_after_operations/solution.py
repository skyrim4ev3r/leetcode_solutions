INT_MIN = -1 - (2 ** 31)

class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:

        nums.sort()

        last_distinct = INT_MIN
        count = 0

        for num in nums:
            max_possible = num + k

            if last_distinct < max_possible:
                last_distinct = max(last_distinct + 1, num - k)
                count += 1

        return count
