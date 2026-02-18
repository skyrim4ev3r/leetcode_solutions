class Solution:
    def isBalanced(self, num: str) -> bool:
        balance = 0

        for (i, ch) in enumerate(num):
            if (i & 1) == 1:
                balance += ord(ch) - ord('0')
            else:
                balance -= ord(ch) - ord('0')

        return balance == 0
