class Solution {
public:
    static void rotate(vector<int>& nums, int k) {
        const size_t len = nums.size();
        const size_t split_point = len - (static_cast<size_t>(k) % len);

        std::reverse(nums.begin(), nums.begin() + split_point);
        std::reverse(nums.begin() + split_point, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
