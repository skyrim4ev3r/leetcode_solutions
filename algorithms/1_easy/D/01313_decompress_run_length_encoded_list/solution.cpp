class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        const size_t len{nums.size()};
        vector<int> res{};

        for (size_t i{0}; i < len - 1; i += 2) {
            res.insert(res.end(), static_cast<size_t>(nums[i]), nums[i + 1]);
        }

        return res;
    }
};
