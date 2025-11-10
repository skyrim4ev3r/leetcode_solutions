class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count = nums[0] >= nums[1] ? INT_MAX : 0;
        for(size_t i{1}, len{nums.size()}; i < len && count < 3; ++i)
            nums[i] == nums[i-1] ? count = INT_MAX : (count & 1) == (nums[i-1] < nums[i]) ? ++count : 1;
        return count == 2;
    }
};
