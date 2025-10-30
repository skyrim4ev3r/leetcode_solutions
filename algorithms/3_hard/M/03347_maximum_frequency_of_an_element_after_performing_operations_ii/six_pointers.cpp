class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        sort(nums.begin(), nums.end());

        const size_t len{nums.size()};

        size_t max_freq{0};
        size_t num_operations_usize{static_cast<size_t>(numOperations)};
        size_t left{0};
        size_t right{0};
        size_t left_single{0};
        size_t right_single{0};
        size_t left_doubled{0};
        size_t right_doubled{0};

        const long long k_i64{static_cast<long long>(k)};
        const long long INT_MAX_i64{static_cast<long long>(INT_MAX)};
        const long long INT_MIN_i64{static_cast<long long>(INT_MIN)};

        while (right < len) {

            // First two-pointers logic
            left = right;
            const int curr{nums[left]};
            const long long curr_i64{static_cast<long long>(curr)};

            while (right < len && nums[right] == curr) {
                right += 1;
            }

            // Second two-pointers logic
            const int min_single{curr - k};
            const int max_single{curr + k};

            while (nums[left_single] < min_single) {
                left_single += 1;
            }

            while (right_single < len && nums[right_single] <= max_single) {
                right_single += 1;
            }

            const size_t total_free_cost{right - left};
            const size_t total_with_cost{right_single - right + left - left_single};
            const size_t curr_freq{total_free_cost + std::min(total_with_cost, num_operations_usize)};
            max_freq = std::max(max_freq, curr_freq);

            // Third two-pointers logic
            const int min_doubled{static_cast<int>(std::max(INT_MIN_i64, curr_i64 - (2 * k_i64)))};
            const int max_doubled{static_cast<int>(std::min(INT_MAX_i64, curr_i64 + (2 * k_i64)))};

            while (nums[left_doubled] < min_doubled) {
                left_doubled += 1;
            }

            while (right_doubled < len && nums[right_doubled] <= max_doubled) {
                right_doubled += 1;
            }

            // Assume that all numbers in this range need operation
            // as an example [1,2,3] k = 1, op = 2
            // then while this conditions cant set max_freq higher than 2,
            // but number "2" can check it when it is candidate with prev conditions as 2 + k, 2 - k
            const size_t total_double_on_left{right - left_doubled};
            max_freq = std::max(max_freq, std::min(total_double_on_left, num_operations_usize));

            const size_t total_double_on_right{right_doubled - left};
            max_freq = std::max(max_freq, std::min(total_double_on_right, num_operations_usize));
        }

        return static_cast<int>(max_freq);
    }
};
