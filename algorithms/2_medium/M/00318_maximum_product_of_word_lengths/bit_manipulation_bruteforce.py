class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        masks = [0] * n

        for i in range(n):
            mask = 0

            for ch in words[i]:
                mask = mask | (1 << (ord(ch) - ord('a')))

            masks[i] = mask

        max_product_len = 0

        for i in range(n):
            for j in range(i + 1, n):
                if (masks[i] & masks[j]) == 0:
                    max_product_len = max(max_product_len, len(words[i]) * len(words[j]))

        return max_product_len
