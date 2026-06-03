class Solution:
    def helper(self, a_start_time: List[int], a_duration: List[int], b_start_time: List[int], b_duration: List[int]) -> int:
        a_len = len(a_start_time)
        b_len = len(b_start_time)

        min_a_end = sys.maxsize
        for i in range(0, a_len):
            min_a_end = min(min_a_end, a_start_time[i] + a_duration[i])

        res = sys.maxsize
        for i in range(0, b_len):
            start_b = max(min_a_end, b_start_time[i])
            end_b = start_b + b_duration[i]

            res = min(res, end_b)

        return res

    def earliestFinishTime(self, land_start_time: List[int], land_duration: List[int], water_start_time: List[int], water_duration: List[int]) -> int:
        land_first = self.helper(land_start_time, land_duration, water_start_time, water_duration)
        water_first = self.helper(water_start_time, water_duration, land_start_time, land_duration)

        return min(land_first, water_first);
