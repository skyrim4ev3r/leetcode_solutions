class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freqs = Counter(arr).values()
        return len(freqs) == len(set(freqs))
