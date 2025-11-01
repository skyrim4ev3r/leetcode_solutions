class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        sort(nums.begin(), nums.end());

        const size_t len{nums.size()};
        size_t max_freq{0};
        const size_t num_operations_usize{static_cast<size_t>(numOperations)};

        const int num_min{nums[0]};
        const int num_max{nums[len - 1]};

        for (int num{num_min}; num <= num_max; ++num) {
            const size_t free_cost_left{static_cast<size_t>(lower_bound(nums.begin(), nums.end(), num) - nums.begin())};
            const size_t free_cost_right{static_cast<size_t>(upper_bound(nums.begin(), nums.end(), num) - nums.begin())};
            const size_t total_free_cost{free_cost_right - free_cost_left};

            const size_t left{static_cast<size_t>(lower_bound(nums.begin(), nums.end(), num - k) - nums.begin())};
            const size_t right{static_cast<size_t>(upper_bound(nums.begin(), nums.end(), num + k) - nums.begin())};

            const size_t total{right - left};
            const size_t total_with_cost{total - total_free_cost};

            const size_t curr_freq{total_free_cost + std::min(total_with_cost, num_operations_usize)};

            max_freq = std::max(max_freq, curr_freq);
        }

        return static_cast<int>(max_freq);
    }
};
