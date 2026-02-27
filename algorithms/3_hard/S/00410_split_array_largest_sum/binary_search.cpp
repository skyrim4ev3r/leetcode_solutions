class Solution {
    static inline bool is_valid(const vector<int>&nums, const int max_valid_sum, const int k) {
        int curr_sum{ 0 };
        int count{ 0 };

        for (const auto& num : nums) {
            if (curr_sum + num <= max_valid_sum) {
                curr_sum += num;
            } else {
                curr_sum = num;
                count += 1;

                if (count == k) {
                    return false;
                }
            }
        }

        return true;
    }
public:
    static int splitArray(const vector<int>& nums, const int k) {
        int high{ std::reduce(nums.cbegin(), nums.cend(), 0) };
        int low{ *ranges::max_element(nums) };

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };

            if (is_valid(nums, mid, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
