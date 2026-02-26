XOR_GROUP_SIZE = 3

class Solution:
    def calc_next_level(self, nums: List[int], unique_xors: Set[int]):
        prev_unique_xors = list(unique_xors)
        unique_xors.clear()

        for num in nums:
            for prev_unique_xor in prev_unique_xors:
                unique_xors.add(num ^ prev_unique_xor)

    def uniqueXorTriplets(self, nums: List[int]) -> int:
        unique_xors = { 0 }

        for _ in range(XOR_GROUP_SIZE):
            self.calc_next_level(nums, unique_xors)

        return len(unique_xors)
