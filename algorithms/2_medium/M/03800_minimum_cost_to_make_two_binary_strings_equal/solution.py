class Solution:
    def minimumCost(self, s: str, t: str, flip_cost: int, swap_cost: int, cross_cost: int) -> int:
        n: int = len(s)
        xy: int = 0
        yx: int = 0

        for i in range(n):
            if s[i] != t[i]:
                if s[i] == '1':
                    xy += 1
                else:
                    yx += 1

        unequal_pairs: int = xy + yx
        possible_direct_swaps: int = min(xy, yx)
        impossible_direct_swaps: int = abs(xy - yx)
        possible_cross: int = impossible_direct_swaps // 2
        force_flips: int = (impossible_direct_swaps & 1)

        all_flips_cost: int = unequal_pairs * flip_cost

        all_flips_swap_cost: int = (
            impossible_direct_swaps * flip_cost +
            possible_direct_swaps * swap_cost
        )

        flips_swap_cross_cost: int = (
            force_flips * flip_cost +
            possible_direct_swaps * swap_cost +
            possible_cross * (cross_cost + swap_cost)
        )

        return min(
            all_flips_cost,
            all_flips_swap_cost,
            flips_swap_cross_cost
        )
