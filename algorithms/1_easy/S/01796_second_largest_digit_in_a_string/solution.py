class Solution:
    def secondHighest(self, s: str) -> int:

        is_seen = [False] * 10

        for ch in s:
            if ch in "0123456789":
                is_seen[ord(ch) - ord('0')] = True

        count = 0

        for i in range(9, -1, -1):
            if is_seen[i]:
                count += 1
                if count == 2:
                    return i

        return -1
