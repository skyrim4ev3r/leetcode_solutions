class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        const size_t len{ nums.size() };
        unordered_set<int> hashset{};

        for (size_t i{ 0 }; i < len; ++i) {
            if (nums[i] != target[i]) {
                hashset.insert(nums[i]);
            }
        }

        return static_cast<int>(hashset.size());
    }
};
