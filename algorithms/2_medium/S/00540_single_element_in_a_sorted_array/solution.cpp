class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const size_t len{nums.size()};

        for (size_t i{0}; i + 1 < len; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        return nums[len - 1];
    }
};
