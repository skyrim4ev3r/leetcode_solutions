class Solution {
    static void backtrack(
        const vector<int>& nums,
        vector<vector<int>>& res,
        vector<int>& temp,
        const size_t curr_index,
        const size_t len
    ) {
        unordered_set<int> visited;
        for (size_t i{ curr_index }; i < len; ++i) {
            if ((temp.empty() || nums[i] >= temp.back()) && visited.insert(nums[i]).second) {
                temp.push_back(nums[i]);
                if (temp.size() > 1) {
                    res.push_back(temp);
                }
                backtrack(nums, res, temp, i + 1, len);
                temp.pop_back();
            }
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
