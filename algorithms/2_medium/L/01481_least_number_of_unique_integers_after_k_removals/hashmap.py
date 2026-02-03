class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        n = len(arr)

        if k >= n:
            return 0

        freqs = list(Counter(arr).values())
        freqs.sort(reverse=True)

        while k >= freqs[-1]:
            k -= freqs[-1]
            freqs.pop()

        return len(freqs)
