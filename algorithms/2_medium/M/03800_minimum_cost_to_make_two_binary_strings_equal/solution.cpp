class Solution {
public:
    static long long minimumCost(
        const string& s,
        const string& t,
        const long long flip_cost,
        const long long swap_cost,
        const long long cross_cost
    ) {
        const size_t len{ s.size() };
        long long xy{ 0 };
        long long yx{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            if (s[i] != t[i]) {
                if (s[i] == '1') {
                    xy += 1;
                } else {
                    yx += 1;
                }
            }
        }

        const long long unequal_pairs{ xy + yx };
        const long long possible_direct_swaps{ std::min(xy, yx) };
        const long long impossible_direct_swaps{ abs(xy - yx) };
        const long long possible_cross{ impossible_direct_swaps / 2 };
        const long long force_flips{ impossible_direct_swaps & 1 };

        const long long all_flips_cost{ unequal_pairs * flip_cost };

        const long long all_flips_swap_cost {
            impossible_direct_swaps * flip_cost +
            possible_direct_swaps * swap_cost
        };

        const long long flips_swap_cross_cost {
            force_flips * flip_cost +
            possible_direct_swaps * swap_cost +
            possible_cross * (cross_cost + swap_cost)
        };

        return std::min(
            all_flips_cost,
            std::min(all_flips_swap_cost, flips_swap_cross_cost)
        );
    }
};
