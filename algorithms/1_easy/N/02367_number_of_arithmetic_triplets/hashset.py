class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        hashset = set()
        count = 0

        for num in nums:
            if (num - diff) in hashset and num - (2 * diff) in hashset:
                count += 1

            hashset.add(num)

        return count
