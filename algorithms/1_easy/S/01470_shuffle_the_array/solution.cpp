class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        const size_t len{nums.size()};
        const size_t half{len / 2};
        vector<int> res;
        res.reserve(len);

        for (size_t i{0}; i < half; ++i) {
            res.push_back(nums[i]);
            res.push_back(nums[i + half]);
        }

        return res;
    }
};
