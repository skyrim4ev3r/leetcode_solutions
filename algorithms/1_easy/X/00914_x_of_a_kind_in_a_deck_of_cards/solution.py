class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        freqs = defaultdict(int)

        for num in deck:
            freqs[num] += 1

        curr_gcd = 0

        for freq in freqs.values():
            curr_gcd = gcd(freq, curr_gcd)

        return curr_gcd > 1
