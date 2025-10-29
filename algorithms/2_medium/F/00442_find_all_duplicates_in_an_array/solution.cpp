class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res{};
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            const size_t num_as_index = static_cast<size_t>(abs(nums[i]) -1);

            if (nums[num_as_index] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[num_as_index] *= -1;
            }
        }

        return res;
    }
};
