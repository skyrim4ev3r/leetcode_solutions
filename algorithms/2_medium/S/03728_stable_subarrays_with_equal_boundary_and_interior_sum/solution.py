MIN_WIDTH = 3

class Solution:
    def countStableSubarrays(self, capacity: List[int]) -> int:
        n = len(capacity)
        count: int = 0
        pref_sum_left: int = 0
        pref_sum_right: int = 0
        freqs = defaultdict(int)

        for i in range(n):
            if i >= MIN_WIDTH - 1:
                val_left: int = capacity[i - (MIN_WIDTH - 1)]
                pref_sum_left += val_left
                freqs[(pref_sum_left, val_left)] += 1

            val_right: int = capacity[i]
            pref_sum_right += val_right
            other_sum: int = pref_sum_right - (2 * val_right)
            count += freqs.get((other_sum, val_right), 0)

        return count
