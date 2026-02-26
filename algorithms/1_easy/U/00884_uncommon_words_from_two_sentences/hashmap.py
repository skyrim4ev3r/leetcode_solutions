class Solution:
    def calc_freqs(self, s, freqs):
        for part in s.split(' '):
            freqs[part] += 1

    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        freqs = defaultdict(int)
        self.calc_freqs(s1, freqs)
        self.calc_freqs(s2, freqs)
        res = []

        for (word, freq) in freqs.items():
            if freq == 1:
                res.append(word)

        return res
