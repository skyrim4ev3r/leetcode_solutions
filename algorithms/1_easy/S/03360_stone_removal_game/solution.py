class Solution:
    def canAliceWin(self, n: int) -> bool:
        step = 10
        is_winning = False

        while step > 0 and step <= n:
            n -= step
            step -= 1
            is_winning = not is_winning

        return is_winning
