class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const size_t len{ nums.size() };

        if (len < 3 || len % 3 != 0) {
            return vector<vector<int>>{};
        }

        ranges::sort(nums);

        for (size_t i{ 0 }; i < len; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return vector<vector<int>>{};
            }
        }

        vector<vector<int>> res;
        res.reserve(len / 3);

        for (size_t i{ 0 }; i < len; i += 3) {
            res.push_back(vector<int>(nums.cbegin() + i, nums.cbegin() + i + 3));
        }

        return res;
    }
};
