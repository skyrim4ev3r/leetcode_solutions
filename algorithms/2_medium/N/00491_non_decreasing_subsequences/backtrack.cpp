
class Solution {
    static void backtrack(
        const vector<int>& nums,
        vector<vector<int>>& res,
        vector<int>& temp,
        const size_t curr_index,
        const size_t len
    ) {
        if (curr_index == len) {
            if (temp.size() > 1) {
                res.push_back(temp);
            }

            return;
        }

        if (temp.empty() || temp.back() <= nums[curr_index]) {
            temp.push_back(nums[curr_index]);
            backtrack(nums, res, temp, curr_index + 1, len);
            temp.pop_back();
        }

        if (temp.empty() || temp.back() != nums[curr_index]) {
            backtrack(nums, res, temp, curr_index + 1, len);
        }
    }
public:
    static vector<vector<int>> findSubsequences(const vector<int>& nums) {
        const size_t len{ nums.size() };
        vector<int> temp{};
        vector<vector<int>> res;

        backtrack(nums, res, temp, 0, len);

        return res;
    }
};
