class Solution {
    static inline int find_dominant(const vector<int>& nums) {
        int curr_freq {0};
        int curr_num {0};

        for (const int& num : nums) {
            if (curr_freq == 0) {
                curr_num = num;
                curr_freq = 1;
            } else {
                if (num != curr_num) {
                    curr_freq -= 1;
                } else {
                    curr_freq += 1;
                }
            }
        }

        return curr_num;
    }
public:
    static int minimumIndex(const vector<int>& nums) {
        const size_t len {nums.size()};
        const int dominant {find_dominant(nums)};
        size_t right_count_dominant {static_cast<size_t>(count(nums.cbegin(), nums.cend(), dominant))};
        size_t left_count_dominant {0};

        for (size_t i {0}; i + 1 < len; ++i) {
            if (nums[i] == dominant) {
                right_count_dominant -= 1;
                left_count_dominant += 1;
            }

            if (left_count_dominant > (i + 1) / 2 && right_count_dominant > (len - i - 1) / 2) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
