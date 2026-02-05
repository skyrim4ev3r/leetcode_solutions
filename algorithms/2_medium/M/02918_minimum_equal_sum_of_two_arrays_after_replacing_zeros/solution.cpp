class Solution {
    static inline pair<long long, long long> calc_sum_and_zeros(const vector<int>& nums) {
        long long sum{ 0 };
        long long zeros{ 0 };

        for (const auto& num : nums) {
            sum += static_cast<long long>(num);

            if (num == 0) {
                zeros += 1;
            }
        }

        return {sum, zeros};
    }
public:
    static long long minSum(const vector<int>& nums1, const vector<int>& nums2) {
        const auto [sum1, zeros1] = calc_sum_and_zeros(nums1);
        const auto [sum2, zeros2] = calc_sum_and_zeros(nums2);
        const long long min_valid_sum1{ sum1 + zeros1 };
        const long long min_valid_sum2{ sum2 + zeros2 };

        if ((zeros1 == 0 && sum1 < min_valid_sum2) || (zeros2 == 0 && min_valid_sum1 > sum2)) {
            return -1;
        }

        return std::max(min_valid_sum1, min_valid_sum2);
    }
};
