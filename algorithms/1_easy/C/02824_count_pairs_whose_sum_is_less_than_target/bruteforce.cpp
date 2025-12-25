class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count {0};
        const size_t len {nums.size()};

        for (size_t i {0}; i < len; ++i) {
            for (size_t j {i + 1}; j < len; ++j) {
                if (nums[i] + nums[j] < target) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
