class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        hashmap = defaultdict(int)

        MOD_TO = 1_000_000_007
        total_trapezoid_count = 0
        total_selection = 0

        for point in points:
            hashmap[point[1]] += 1

        for count in hashmap.values():
            if count > 1:
                curr_selection = ((count * (count - 1)) // 2) % MOD_TO
                total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO
                total_selection = (total_selection + curr_selection) % MOD_TO

        return total_trapezoid_count
