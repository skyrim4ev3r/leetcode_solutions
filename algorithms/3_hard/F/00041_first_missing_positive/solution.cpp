class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n{nums.size()};

        for (int &num: nums) {
            if (num <= 0) {
                num = INT_MAX;
            }
        }

        for (size_t i{0}; i < n; ++i) {
            int num_as_index = abs(nums[i]) - 1;
            if (num_as_index < n) {
                if (nums[num_as_index] > 0) {
                    nums[num_as_index] *= -1;
                }
            }
        }

        for (size_t i{0}; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
