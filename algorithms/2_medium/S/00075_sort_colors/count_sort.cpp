class Solution {
public:
    void sortColors(vector<int>& nums) {

        const size_t colors_len{3};
        int colors_count[colors_len]{};

        for (int &num: nums) {
            colors_count[static_cast<size_t>(num)] += 1;
        }

        size_t nums_index = 0;
        for (size_t i{0}; i < colors_len; ++i) {
            int i_32 = static_cast<int>(i);
            for (int k{0}; k < colors_count[i]; ++k) {
                nums[nums_index] = i_32;
                nums_index += 1;
            }
        }
    }
};
