class Solution {
    static inline int calc_subarray_score(
        const vector<int>& nums,
        const size_t start,
        const size_t end,
        const int negative_count
    ) {
        if ((negative_count & 1) == 0) {
            return static_cast<int>(end - start);
        }

        size_t left{ start };
        size_t right { end - 1 };

        while (nums[left] > 0) {
            left += 1;
        }

        while (nums[right] > 0) {
            right -= 1;
        }

        size_t max_width{ std::max(right - start, end - 1 - left)};

        return static_cast<int>(max_width);
    }

public:
    static int getMaxLen(const vector<int>& nums) {
        const size_t len{ nums.size() };
        int negative_count{ 0 };
        int max_score{ 0 };
        size_t left{ 0 };
        size_t right{ 0 };

        for (const auto& num : nums) {
            if (num < 0) {
                negative_count += 1;
            }

            if (num == 0) {
                const int curr_score{ calc_subarray_score(nums, left, right, negative_count) };

                max_score = std::max(max_score, curr_score);
                left = right + 1;
                negative_count = 0;
            }

            right += 1;
        }

        const int curr_score{ calc_subarray_score(nums, left, right, negative_count) };
        max_score = std::max(max_score, curr_score);

        return max_score;
    }
};
