class Solution {
public:
    static int firstMissingPositive(vector<int>& nums) {
        const size_t len = nums.size();

        for (int& num : nums) {
            if (num <= 0) {
                num = numeric_limits<int>::max();
            }
        }

        for (size_t i = 0; i < len; i += 1) {
            const size_t num_index = abs(nums[i]) - 1;
            if (num_index < len && nums[num_index] > 0) {
                nums[num_index] *= -1;
            }
        }

        for (size_t i = 0; i < len; i += 1) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return static_cast<int>(len + 1);
    }
};
