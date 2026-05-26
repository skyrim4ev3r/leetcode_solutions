class Solution {
public:
    static void sortColors(vector<int>& nums) noexcept {
        const size_t len = nums.size();
        constexpr size_t COLOR_COUNT = 3;
        int freqs[COLOR_COUNT] = { 0 };

        for (const int num : nums) {
            freqs[static_cast<size_t>(num)] += 1;
        }

        size_t nums_index = 0;
        for (size_t i = 0; i < COLOR_COUNT; i += 1) {
            const int freq = freqs[i];
            int color = static_cast<int>(i);
            for (int k = 0; k < freq; k += 1) {
                nums[nums_index] = color;
                nums_index += 1;
            }
        }
    }
};
