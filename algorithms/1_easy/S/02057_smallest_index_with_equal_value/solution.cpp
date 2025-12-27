class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        const size_t len {nums.size()};

        for (size_t i {0}; i < len; ++i) {
            if (static_cast<int>(i) % 10 == nums[i]) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
