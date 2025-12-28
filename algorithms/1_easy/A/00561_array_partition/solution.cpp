class Solution {
public:
    static inline int arrayPairSum(vector<int>& nums) {
        const size_t len {nums.size()};
        int res {0};

        ranges::sort(nums);

        for (size_t i {0}; i < len; i += 2) {
            res += nums[i];
        }

        return res;
    }
};
