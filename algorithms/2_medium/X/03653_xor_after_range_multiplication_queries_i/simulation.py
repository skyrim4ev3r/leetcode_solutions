DIV = 1_000_000_007

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for query in queries:
            right = query[1]
            step = query[2]
            v = query[3]

            for left in range(query[0], right + 1, step):
                nums[left] = nums[left] * v % DIV

        res = 0

        for num in nums:
            res ^= num

        return res
