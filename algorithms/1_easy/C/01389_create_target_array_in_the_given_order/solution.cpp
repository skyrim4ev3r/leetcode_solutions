class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        const size_t len{nums.size()};
        vector<int> res{};
        res.reserve(len);

        for (size_t i{0}; i < len; ++i) {
            res.insert(res.begin() + index[i], nums[i]);
        }

        return res;
    }
};
