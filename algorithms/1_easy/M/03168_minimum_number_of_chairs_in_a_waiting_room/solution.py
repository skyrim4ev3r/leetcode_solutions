class Solution:
    def minimumChairs(self, s: str) -> int:

        max_chairs = 0
        balance = 0

        for ch in s:
            if ch == 'E':
                balance += 1
                max_chairs = max(max_chairs, balance)
            else:
                balance -= 1

        return max_chairs
