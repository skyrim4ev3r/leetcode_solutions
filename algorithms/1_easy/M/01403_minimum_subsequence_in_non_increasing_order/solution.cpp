class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int sum_left{accumulate(nums.begin(), nums.end(), 0)};
        int sum_right{0};
        size_t index{nums.size() - 1};
        vector<int> res{};

        while (sum_left >= sum_right) {
            sum_right += nums[index];
            sum_left -= nums[index];
            res.push_back(nums[index]);
            index -= 1;
        }

        return res;
    }
};
