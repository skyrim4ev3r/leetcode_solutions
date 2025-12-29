class Solution {
    static inline long long minimumCost_i64(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        const long long buy_base_together {std::min(need1, need2) * costBoth};
        const long long buy_extra_together {abs(need2 - need1) * costBoth};
        const long long buy_extra_seperate {need2 > need1 ? cost2 * (need2 - need1) : cost1 * (need1 - need2)};

        const long long buy_together {buy_base_together + std::min(buy_extra_together, buy_extra_seperate)};
        const long long buy_seperate {(cost1 * need1) + (cost2 * need2)};

        return std::min(buy_seperate, buy_together);
    }
public:
    static long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return minimumCost_i64(cost1, cost2, costBoth, need1, need2);
    }
};
