class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        size_t left{0};
        size_t len{nums.size()};
        int count_zeros{0};
        int max{0};

        for (size_t right{0}; right < len; ++right) {
            if (nums[right] == 0) {
                count_zeros += 1;
            }

            while (count_zeros > k) {
                if (nums[left] == 0) {
                    count_zeros -= 1;
                }
                left += 1;
            }

            if (left <= right) {
                max = std::max(max, static_cast<int>(right - left + 1));
            }
        }

        return max;
    }
};
