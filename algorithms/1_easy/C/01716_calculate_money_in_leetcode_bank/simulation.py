class Solution:
    def totalMoney(self, n: int) -> int:

        curr_investment = 1
        total_investment = 0

        for day in range(1, n + 1):
            total_investment += curr_investment
            curr_investment += 1
            if day % 7 == 0:
                curr_investment -=  6

        return total_investment
