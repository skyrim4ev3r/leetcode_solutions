class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashset = set()

        for i, num in enumerate(nums):
            if i > k:
                hashset.remove(nums[i - k - 1])

            if num in hashset:
                return True

            hashset.add(num)

        return False
