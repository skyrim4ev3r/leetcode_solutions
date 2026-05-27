class Solution {
    static void backtrack(const vector<int>& nums, const size_t nums_len, const size_t nums_idx, vector<vector<int>>& res, vector<int>& curr_vec) {
        if (nums_idx == nums_len) {
            res.push_back(curr_vec);
            return;
        }

        backtrack(nums, nums_len, nums_idx + 1, res, curr_vec);
        curr_vec.push_back(nums[nums_idx]);
        backtrack(nums, nums_len, nums_idx + 1, res, curr_vec);
        curr_vec.pop_back();
    }

public:
    static vector<vector<int>> subsets(const vector<int>& nums) {
        const size_t nums_len = nums.size();
        const size_t nums_idx = 0;

        const size_t res_capacity = 1u << nums_len;
        vector<vector<int>> res;
        res.reserve(res_capacity);

        const size_t curr_vec_capacity = nums_len;
        vector<int> curr_vec{};
        curr_vec.reserve(curr_vec_capacity);

        backtrack(nums, nums_len, nums_idx, res, curr_vec);

        return res;
    }
};
