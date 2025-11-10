class Solution {
public:
    bool isTrionic(vector<int>& nums, size_t index = 0, int count = 0) {
        return count <= 2 && nums[0] < nums[1] && (index == nums.size() - 1 ? (count == 2 ? true: false) : isTrionic(nums, index + 1, nums[index] == nums[index + 1] ? INT_MAX: ((count & 1) == (nums[index] > nums[index + 1]) ? count : count + 1)));
    }
};
