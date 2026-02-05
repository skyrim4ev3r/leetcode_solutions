class Solution {
public:
    static int maxFrequency(vector<int>& nums, const int k) {
        ranges::sort(nums);

        long long curr_cost{ 0 };
        size_t left{ 0 };
        size_t max_width{ 1 };
        const size_t len{ nums.size() };
        const long long k_i64{ static_cast<long long>(k) };

        for (size_t right{ 1 }; right < len; ++right) {
            const long long inc_amount{ static_cast<long long>(nums[right] - nums[right - 1]) };
            const long long count_prev_nums{ static_cast<long long>(right - left) };
            curr_cost += inc_amount * count_prev_nums;

            while (curr_cost > k_i64) {
                curr_cost -= static_cast<long long>(nums[right] - nums[left]);
                left += 1;
            }

            max_width = std::max(max_width, right - left + 1);
        }

        return static_cast<int>(max_width);
    }
};
