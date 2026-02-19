class Solution:
    def prefixConnected(self, words: List[str], k: int) -> int:
        hashmap = defaultdict(int)

        for w in words:
            if len(w) >= k:
                hashmap[w[:k]] += 1

        count = 0

        for v in hashmap.values():
            if v > 1:
                count += 1

        return count
