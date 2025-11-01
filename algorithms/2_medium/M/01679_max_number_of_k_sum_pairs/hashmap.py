class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:

        hashmap = {}
        count = 0

        for num in nums:
            other = k - num

            if other in hashmap and hashmap[other] > 0:
                hashmap[other] -= 1
                count += 1
            else:
                if num in hashmap:
                    hashmap[num] += 1
                else:
                    hashmap[num] = 1

        return count
