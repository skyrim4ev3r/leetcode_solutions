class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        hashset = set()

        for num in nums:
            if num % k == 0:
                hashset.add(num)

        curr = k

        while curr in hashset:
            curr += k

        return curr
