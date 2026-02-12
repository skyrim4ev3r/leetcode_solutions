class Solution {
public:
    int minOperations(vector<int>& nums) {
        return (std::any_of(nums.begin(), nums.end(), [&](int num){ return num != nums[0];})) ? 1 : 0;
    }
};
