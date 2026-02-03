class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        hashset = set()
        max_sum = 0
        curr_sum = 0
        left = 0
        n = len(nums)

        for right in range(n):
            num = nums[right]
            while num in hashset:
                hashset.remove(nums[left])
                curr_sum -= nums[left]
                left += 1

            curr_sum += num
            hashset.add(num)
            max_sum = max(max_sum, curr_sum)

        return max_sum
