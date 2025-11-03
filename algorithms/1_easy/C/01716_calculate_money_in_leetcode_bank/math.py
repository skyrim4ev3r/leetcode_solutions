class Solution:
    def totalMoney(self, n: int) -> int:

        complete_weeks = n // 7
        remain_days = n % 7

        base_money_for_full_weeks = ((7 * (7 + 1)) // 2) * complete_weeks
        growth_money_for_full_weeks = (((complete_weeks -1) * complete_weeks) // 2) * 7

        base_money_last_week = (remain_days * (remain_days + 1)) // 2
        growth_money_last_week = complete_weeks * remain_days

        return base_money_for_full_weeks + growth_money_for_full_weeks + \
        base_money_last_week + growth_money_last_week
