class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freqs = Counter(words)
        freqs_vec = sorted(freqs.items(), key= lambda x: (-x[1], x[0]))
        return [freqs_vec[i][0] for i in range(k)]
