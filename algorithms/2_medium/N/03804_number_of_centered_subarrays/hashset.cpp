class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        const size_t len{ nums.size() };
        int count{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            int sum{ 0 };
            unordered_set<int> hashset{};

            for (size_t j{ i }; j < len; ++j) {
                sum += nums[j];
                hashset.insert(nums[j]);

                if (hashset.contains(sum)) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
