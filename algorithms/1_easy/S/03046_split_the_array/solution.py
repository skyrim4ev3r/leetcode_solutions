class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        hashmap = defaultdict(int)

        for num in nums:
            hashmap[num] += 1

            if hashmap[num] > 2:
                return False

        return True
