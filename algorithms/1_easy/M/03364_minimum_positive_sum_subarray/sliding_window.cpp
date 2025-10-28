class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const size_t len{nums.size()};
        int min_positive_sum{-1};
        const size_t min_width{static_cast<size_t>(l)};
        const size_t max_width{static_cast<size_t>(r)};

        for (size_t width{min_width}; width <= max_width; ++width) {
            int sum{0};
            size_t left{0};
            size_t right{width - 1};

            for (size_t i{left}; i <= right; ++i) {
                sum += nums[i];
            }

            while (right < len) {
                if (sum > 0 && (sum < min_positive_sum || min_positive_sum == -1)) {
                    min_positive_sum = sum;
                }

                right += 1;
                if (right < len) {
                    sum += nums[right];
                    sum -= nums[left];
                    left += 1;
                }
            }
        }

        return min_positive_sum;
    }
};
