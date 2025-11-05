class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const size_t len{nums.size()};

        sort(nums.rbegin(), nums.rend());

        for (size_t i{0}; i < len - 2; ++i) {
             if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
             }
        }

        return 0;
    }
};
