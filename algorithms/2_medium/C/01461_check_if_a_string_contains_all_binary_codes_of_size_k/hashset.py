class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        return len(set([int(s[i - k : i], 2) for i in range(k, len(s) + 1)])) == pow(2, k)
