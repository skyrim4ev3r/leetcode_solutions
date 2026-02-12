class Solution {
    static inline bool is_possible(const vector<int>& nums, const int divisor, const int threshold) {
        int sum{ 0 };

        for (const auto& num : nums) {
            sum += (num + divisor - 1) / divisor;

            if (sum > threshold) {
                return false;
            }
        }

        return true;
    }
public:
    static int smallestDivisor(const vector<int>& nums, const int threshold) {
        int low{ 1 };
        int high{ 1 + *std::max_element(nums.cbegin(), nums.cend()) };

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };

            if (is_possible(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
