class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        min_diff = -1

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if nums[i] == nums[j] and nums[j] == nums[k]:
                        curr_diff = (k - i) * 2

                        if min_diff == -1 or curr_diff < min_diff:
                            min_diff = curr_diff

        return min_diff
