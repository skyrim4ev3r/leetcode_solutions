class Solution {
public:
    static vector<int> leftRightDifference(vector<int>& nums) {
        int sum_to_right = std::reduce(nums.begin(), nums.end(), 0);
        int sum_to_left = 0;

        for (auto& num_ref : nums)  {
            const int original_val = num_ref;
            sum_to_right -= original_val;
            num_ref = std::abs(sum_to_right - sum_to_left);
            sum_to_left += original_val;
        }

        return std::move(nums);
    }
};
