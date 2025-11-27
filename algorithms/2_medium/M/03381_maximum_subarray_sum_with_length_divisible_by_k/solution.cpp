class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const size_t k_usize{static_cast<size_t>(k)};
        const size_t len{nums.size()};
        long long max{numeric_limits<long long>::min()};
        long long pref_sum{0};
        vector<long long> min_pref(k_usize, numeric_limits<long long>::max() / 2);
        min_pref[k_usize - 1] = 0;

        for (size_t i = 0; i < len; ++i) {
            const size_t min_pref_index{i % k_usize};

            pref_sum += static_cast<long long>(nums[i]);
            max = std::max(max, pref_sum - min_pref[min_pref_index]);
            min_pref[min_pref_index] = min(min_pref[min_pref_index], pref_sum);
        }

        return max;
    }
};
