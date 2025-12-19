class Solution {
    static void backtrack(
        const vector<int>& nums,
        vector<vector<int>>& res,
        vector<int>& temp,
        const size_t curr_index,
        const size_t len
    ) {
        res.push_back(temp);

        for  (size_t i{curr_index}; i < len; ++i) {
            if (i > curr_index && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);
            backtrack(nums, res, temp, i + 1, len);
            temp.pop_back();
        }
    }

public:
    static vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp{};
        vector<vector<int>> res{};

        sort(nums.begin(), nums.end());
        backtrack(nums, res, temp, 0, nums.size());

        return res;
    }
};
