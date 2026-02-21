class Solution {
public:
    static int countElements(vector<int>& nums, int k) {
        const size_t len{ nums.size() };

        if (k == 0) {
            return static_cast<int>(len);
        }

        ranges::sort(nums);
        const int k_th_biggest{ nums[len - static_cast<size_t>(k)] };

        return static_cast<int>(ranges::lower_bound(nums, k_th_biggest) - nums.begin());
    }
};
