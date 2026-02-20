class Solution {
public:
    static int minOperations(const vector<int>& nums) {
        const size_t len{ nums.size() };
        unordered_set<int> seen{};

        for (size_t i{ len - 1 }; i < len; --i) {
            if (!seen.insert(nums[i]).second) {
                return static_cast<int>((i / 3) + 1);
            }
        }

        return 0;
    }
};
