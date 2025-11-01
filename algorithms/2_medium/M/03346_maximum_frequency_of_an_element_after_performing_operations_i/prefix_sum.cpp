class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int max_freq{0};

        int max_val{INT_MIN};
        int min_val{INT_MAX};

        for (const int &num: nums) {
            max_val = std::max(max_val, num);
            min_val = std::min(min_val, num);
        }

        const size_t counts_len{static_cast<size_t>(max_val - min_val + 2)};
        vector<int> counts(counts_len, 0);

        for (const int &num: nums) {
            counts[static_cast<size_t>(num - min_val + 1)] += 1;
        }

        for (size_t i{1}; i < counts_len; ++i) {
            counts[i] += counts[i - 1];
        }

        for (size_t i{1}; i < counts_len; ++i) {
            const int curr{static_cast<int>(i)};

            const size_t left{static_cast<size_t>(std::max(1, curr - k))};
            const size_t right{static_cast<size_t>(std::min(max_val - min_val + 1, curr + k))};

            const int total{counts[right] - counts[left - 1]};
            const int total_free_cost{counts[i] - counts[i - 1]};
            const int total_with_cost{total - total_free_cost};

            const int curr_freq{total_free_cost + std::min(total_with_cost, numOperations)};

            max_freq = std::max(max_freq, curr_freq);
        }

        return max_freq;
    }
};
