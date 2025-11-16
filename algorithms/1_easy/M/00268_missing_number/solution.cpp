class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const size_t len{nums.size()};

        for (int& num : nums) {
            const size_t index{static_cast<size_t>(num < 0 ? abs(num) - 1: num)};

            if (index != len) {
                nums[index] = -1 * nums[index] - 1;
            }
        }

        for (int index{0}; const int& num : nums) {
            if (num >= 0) {
                return index;
            }

            index += 1;
        }

        return static_cast<int>(len);
    }
};
