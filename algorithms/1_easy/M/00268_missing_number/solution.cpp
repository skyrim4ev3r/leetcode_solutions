class Solution {
public:
    static int missingNumber(vector<int>& nums) {
        const ptrdiff_t len = std::ssize(nums);
        assert(len > 0);

        for (ptrdiff_t i = 0; i < len; i += 1) {
            const ptrdiff_t num_as_index = nums[i] < 0 ? abs(nums[i]) - 1: nums[i];
            assert(num_as_index <= len);

            if (num_as_index != len) {
                nums[num_as_index] = -1 * nums[num_as_index] - 1;
            }
        }

        for (ptrdiff_t i = 0; i < len; i += 1) {
            if (nums[i] >= 0) {
                return static_cast<int>(i);
            }

            i += 1;
        }

        return static_cast<int>(len);
    }
};
