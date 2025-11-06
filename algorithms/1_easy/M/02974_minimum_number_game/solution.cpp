class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        const size_t len{nums.size()};

        sort(nums.begin(), nums.end());

        for (size_t i{0}; i < len - 1; i += 2) {
            const int tmp = nums[i + 1];
            nums[i + 1] = nums[i];
            nums[i] = tmp;
        }

        return nums;
    }
};
