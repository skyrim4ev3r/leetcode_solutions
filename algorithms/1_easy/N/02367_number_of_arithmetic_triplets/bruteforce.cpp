class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        const size_t len{nums.size()};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{i + 1}; j < len; ++j) {
                for (size_t k{j + 1}; k < len; ++k) {
                    if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
