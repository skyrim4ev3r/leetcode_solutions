class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int duplicate_num{-1};
        int missing_num{-1};
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            size_t index{static_cast<size_t>(abs(nums[i]) - 1)};
            if (nums[index] < 0) {
                duplicate_num = abs(nums[i]);
            } else {
                nums[index] *= -1;
            }
        }

         for (size_t i{0}; i < len; ++i) {
            if (nums[i] > 0) {
                missing_num = static_cast<int>(i) + 1;
                break;
            } 
        }

        return vector<int>{duplicate_num, missing_num};
    }
};
