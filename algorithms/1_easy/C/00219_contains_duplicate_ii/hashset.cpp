class Solution {
public:
    static bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        const size_t k_usize{static_cast<size_t>(k)};
        const size_t len{nums.size()};
        unordered_set<int> hashset{};

        for (size_t i{0}; i < nums.size(); ++i) {
            if (i > k_usize) {
                hashset.erase(nums[i - k_usize - 1]);
            }

            if (!hashset.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }
};
