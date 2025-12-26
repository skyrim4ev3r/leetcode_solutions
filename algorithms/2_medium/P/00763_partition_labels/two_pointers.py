class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        last_seen = [n] * 26
        res = []

        for (i, ch) in enumerate(s):
            last_seen[ord(ch) - ord('a')] = i

        left = 0
        target_right = 0

        for right in range(n):
            target_right = max(target_right, last_seen[ord(s[right]) - ord('a')])

            if target_right == right:
                res.append(right - left + 1)
                left = right + 1

        return res
