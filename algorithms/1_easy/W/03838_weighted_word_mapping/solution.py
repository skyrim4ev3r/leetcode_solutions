class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        res = []

        for word in words:
            curr_sum = 0
            for ch in word:
                curr_sum += weights[ord(ch) - ord('a')]
            reversed_offset = 25 - (curr_sum % 26)
            res.append(chr(reversed_offset + ord('a')))

        return "".join(res)
