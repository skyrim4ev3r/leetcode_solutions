class Solution:
    def minSwaps(self, s: str) -> int:
        curr_balance = 0
        min_balance = 0

        for ch in s:
            if ch == '[':
                curr_balance += 1
            else:
                curr_balance -= 1

            min_balance = min(min_balance, curr_balance)

        return (abs(min_balance) + 1) // 2
