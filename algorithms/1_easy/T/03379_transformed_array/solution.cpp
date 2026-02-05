class Solution {
public:
    static vector<int> constructTransformedArray(vector<int>& nums) {
        const size_t len{ nums.size() };
        vector<int> res(len, 0);

        for (size_t i{ 0 }; i < len; ++i) {
            const int steps{ nums[i] % static_cast<int>(len) };
            const int target_index{ (static_cast<int>(i) + steps + static_cast<int>(len)) % static_cast<int>(len) };
            res[i] = nums[static_cast<size_t>(target_index)];
        }

        return res;
    }
};
