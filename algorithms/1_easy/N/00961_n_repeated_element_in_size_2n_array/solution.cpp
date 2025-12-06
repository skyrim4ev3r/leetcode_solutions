class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const size_t len{nums.size()};

        for (size_t i{0}; i + 2 < len; ++i) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }

            if (nums[i + 1] == nums[i + 2]) {
                return nums[i + 1];
            }
        }

        if (nums[0] == nums[len - 1]) {
            return nums[0];
        }

        return -1;
    }
};
