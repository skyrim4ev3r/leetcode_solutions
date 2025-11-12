class Solution {
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, const size_t len, size_t curr_idx) {
        res.push_back(temp);

        for (size_t i{curr_idx}; i < len; ++i) {
            temp.push_back(nums[i]);
            backtrack(res, nums, temp, len, i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const size_t len{nums.size()};
        vector<vector<int>> res{};
        vector<int> temp{};
        temp.reserve(len);

        backtrack(res, nums, temp, len, 0);

        return res;
    }
};
