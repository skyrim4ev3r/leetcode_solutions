class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        freqs1 = defaultdict(int)
        freqs2 = defaultdict(int)
        count = 0

        for word in words1:
            freqs1[word] += 1

        for word in words2:
            freqs2[word] += 1

        for word, freq1 in freqs1.items():
            if freq1 == 1:
                if freqs2.get(word) == 1:
                    count += 1

        return count
