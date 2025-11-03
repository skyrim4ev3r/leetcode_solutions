class Solution {
public:
    int totalMoney(int n) {
        int complete_weeks{n / 7};
        int remain_days{n % 7};

        int base_money_for_full_weeks{((7 * (7 + 1)) / 2) * complete_weeks};
        int growth_money_for_full_weeks{(((complete_weeks -1) * complete_weeks) / 2) * 7};

        int base_money_last_week{(remain_days * (remain_days + 1)) / 2};
        int growth_money_last_week{complete_weeks * remain_days};

        return base_money_for_full_weeks + growth_money_for_full_weeks +
                base_money_last_week + growth_money_last_week;
    }
};
