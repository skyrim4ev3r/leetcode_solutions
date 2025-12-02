class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0

        for d in range(n - 1, -1, -1):
            for c in range(d - 1, -1, -1):
                for b in range(c - 1, -1, -1):
                    for a in range(b - 1, -1, -1):
                        if nums[d] == nums[a] + nums[b] + nums[c]:
                            count += 1

        return count
