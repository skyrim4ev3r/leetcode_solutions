class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int max1{INT_MIN};
        int max2{INT_MIN};
        size_t max1_index{0};
        const size_t nums_len{nums.size()};

        for (size_t i{0}; i < nums_len; ++i) {
            if (nums[i] >= max1) {
                max2 = max1;
                max1 = nums[i];
                max1_index = i;
            } else if (nums[i] >= max2) {
                max2 = nums[i];
            }
        }

        if (max2 * 2 <= max1) {
            return static_cast<int>(max1_index);
        }

        return -1;
    }
};
