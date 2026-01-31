class Solution:
    def centeredSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0

        for i in range(n):
            curr_sum = 0
            hashset = set()

            for j in range(i, n):
                curr_sum += nums[j]
                hashset.add(nums[j])

                if curr_sum in hashset:
                    count += 1

        return count
