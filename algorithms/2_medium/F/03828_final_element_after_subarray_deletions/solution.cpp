class Solution {
public:
    static int finalElement(const vector<int>& nums) {
        return std::max(nums[0], nums.back());
    }
};
