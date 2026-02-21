class Solution {
public:
    static long long splitArray(const vector<int>& nums) {
        const size_t len{ nums.size() };

        size_t left{ 0 };
        while (left + 1 < len && nums[left] < nums[left + 1]) {
            left += 1;
        }

        size_t right{ len - 1 };
        while (right > 0 && nums[right - 1] > nums[right]) {
            right -= 1;
        }

        if (left == right) {
            const size_t index{ left };
            const long long sum_left_part{ reduce(nums.cbegin(), nums.cbegin() + index, 0LL) };
            const long long sum_right_part{ reduce(nums.cbegin() + index + 1, nums.cend(), 0LL) };

            if (index == len - 1) {
                return abs(sum_left_part - static_cast<long long>(nums[index]));
            } else if (index == 0) {
                return abs(static_cast<long long>(nums[index]) - sum_right_part);
            } else {
                const long long max{ std::max(sum_left_part, sum_right_part) };
                const long long min{ std::min(sum_left_part, sum_right_part) };

                return abs(max - (min + static_cast<long long>(nums[index])));
            }
        } else if (left + 1 == right) {
            const long long sum_left_part{ reduce(nums.cbegin(), nums.cbegin() + left + 1, 0LL) };
            const long long sum_right_part{ reduce(nums.cbegin() + right, nums.cend(), 0LL) };

            return abs(sum_left_part - sum_right_part);
        } else {
            return -1;
        }
    }
};
