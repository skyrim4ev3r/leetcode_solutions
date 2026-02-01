class Solution {
public:
    int minimumCost(vector<int>& nums) {
        std::sort(nums.begin() + 1, nums.end());
        return reduce(nums.begin(), nums.begin() + 3);
    }
};
