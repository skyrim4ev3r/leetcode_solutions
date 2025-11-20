class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const size_t len{nums.size()};
        int min_diff{-1};

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{i + 1}; j < len; ++j) {
                for (size_t k{j + 1}; k < len; ++k) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        const int curr_diff{static_cast<int>((k - i) * 2)};

                        if (min_diff == -1 || curr_diff < min_diff) {
                            min_diff = curr_diff;
                        }
                    }
                }
            }
        }

        return min_diff;
    }
};
