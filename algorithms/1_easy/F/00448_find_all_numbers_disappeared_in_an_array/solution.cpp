class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            size_t index{static_cast<size_t>(abs(nums[i]) - 1)};
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }

        vector<int> res{};

        for (size_t i{0}; i < len; ++i) {
            if (nums[i] > 0) {
                res.push_back(static_cast<int>(i) + 1);
            }
        }

        return res;
    }
};
