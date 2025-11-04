class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const size_t len{nums.size()};
        const size_t k_usize{static_cast<size_t>(k) % len};

        size_t left{0};
        size_t right{len - k_usize - 1};

        while (left < right) {
            const int temp{nums[left]};
            nums[left] = nums[right];
            nums[right] = temp;
            left += 1;
            right -= 1;
        }

        left = len - k_usize;
        right = len - 1;

        while (left < right) {
            const int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left += 1;
            right -= 1;
        }

        reverse(nums.begin(), nums.end());
    }
};
