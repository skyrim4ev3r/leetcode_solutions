class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const size_t len{ nums.size() };
        size_t longest{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            unordered_set<int> evens;
            unordered_set<int> odds;

            for (size_t j{ i }; j < len; ++j) {
                if ((nums[j] & 1) == 0) {
                    odds.insert(nums[j]);
                } else {
                    evens.insert(nums[j]);
                }

                if (odds.size() == evens.size()) {
                    longest = std::max(longest, j - i + 1);
                }
            }
        }

        return static_cast<int>(longest);
    }
};
