class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1

        if n == 3:
            return 2

        count_two = 0
        count_three = n // 3
        reminder = n % 3

        if reminder == 1:
            count_two = 2
            count_three -= 1
        elif reminder == 2:
            count_two = 1

        return (3 ** count_three) * (2 ** count_two)
