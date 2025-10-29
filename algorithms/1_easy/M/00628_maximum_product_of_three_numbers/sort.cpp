class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        size_t len{nums.size()};

        sort(nums.begin(), nums.end());

        return std::max(nums[0] * nums[1] * nums[len - 1], nums[len - 1] * nums[len - 2] * nums[len - 3]);
    }
};
