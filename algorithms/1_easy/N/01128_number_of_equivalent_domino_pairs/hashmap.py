class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:

        hashmap = {}

        for d in dominoes:
            hash_index = (min(d[0], d[1]), max(d[0], d[1]))
            if hash_index in hashmap:
                hashmap[hash_index] += 1
            else:
                hashmap[hash_index] = 1

        total = 0

        for val in hashmap.values():
            total += (val * (val - 1)) // 2

        return total
