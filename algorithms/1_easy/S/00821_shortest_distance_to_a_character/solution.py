class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        res = [sys.maxsize] * n
        last_pos = -1

        for i, ch in enumerate(s):
            if ch == c:
                last_pos = i

            if last_pos != -1:
                res[i] = i - last_pos

        last_pos = -1
        for i, ch in enumerate(reversed(s)):
            if ch == c:
                last_pos = i

            if last_pos != -1:
                res[n - 1 - i] = min(res[n - 1 - i], i - last_pos)

        return res
