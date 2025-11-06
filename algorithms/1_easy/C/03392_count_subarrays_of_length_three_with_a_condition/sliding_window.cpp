class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        const size_t len{nums.size()};
        int count{0};

        for (size_t i{0}; i < len - 2; ++i) {
            if ((nums[i + 1] & 1) == 0 && (nums[i] + nums[i + 2]) == nums[i + 1] / 2) {
                count += 1;
            }
        }

        return count;
    }
};
