class Solution:
    def minLengthAfterRemovals(self, s: str) -> int:
        balance = 0

        for ch in s:
            if ch == 'a':
                balance += 1
            else:
                balance -= 1

        return abs(balance)
