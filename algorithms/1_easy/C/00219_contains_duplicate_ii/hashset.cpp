class Solution {
public:
    static bool containsNearbyDuplicate(const vector<int>& nums, int k_i32) {
        const ptrdiff_t len = std::ssize(nums);
        const ptrdiff_t k = k_i32;
        auto hashset = unordered_set<int>();

        for (ptrdiff_t i = 0; i < len; i += 1) {
            if (i > k) {
                hashset.erase(nums[i - k - 1]);
            }

            if (!hashset.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }
};
