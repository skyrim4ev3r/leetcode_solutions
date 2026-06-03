class Solution {
    static int helper(
        const vector<int>& a_start_time,
        const vector<int>& a_duration,
        const vector<int>& b_start_time,
        const vector<int>& b_duration
    ) {
        const size_t a_len = a_start_time.size();
        const size_t b_len = b_start_time.size();

        int min_a_end = numeric_limits<int>::max();
        for (size_t i = 0; i < a_len; i += 1) {
            min_a_end = std::min(min_a_end, a_start_time[i] + a_duration[i]);
        }

        int res = numeric_limits<int>::max();
        for (size_t i = 0; i < b_len; i += 1) {
            const int start_b = std::max(min_a_end, b_start_time[i]);
            const int end_b = start_b + b_duration[i];

            res = std::min(res, end_b);
        }

        return res;
    }

public:
    static int earliestFinishTime(
        const vector<int>& land_start_time,
        const vector<int>& land_duration,
        const vector<int>& water_start_time,
        const vector<int>& water_duration
    ) {
        const int land_first = helper(land_start_time, land_duration, water_start_time, water_duration);
        const int water_first = helper(water_start_time, water_duration, land_start_time, land_duration);

        return std::min(land_first, water_first);
    }
};
