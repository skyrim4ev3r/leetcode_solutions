class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        const size_t k_usize{static_cast<size_t>(k)};
        size_t left{0};
        size_t right{(2 * k_usize) - 1};
        const size_t len{nums.size()};

        while (right < len) {
            bool is_increasing = true;

            for (size_t i{left + 1}; i <= right; ++i) {
                if (i == left + k_usize) {
                    continue;
                }

                if (nums[i - 1] >= nums[i]) {
                    is_increasing = false;
                    break;
                }
            }

            if (is_increasing) {
                return true;
            }

            left += 1;
            right += 1;
        }

        return false;
    }
};
