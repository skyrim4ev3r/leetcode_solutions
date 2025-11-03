class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:

        nums_len = len(nums)
        count = 0

        for i in range(nums_len):
            for j in range((i + 1), nums_len):
                if nums[i] == nums[j] and (i * j) % k == 0:
                    count += 1

        return count
