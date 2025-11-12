class Solution {
public:
    int minOperations(vector<int>& nums) {
        const size_t len{nums.size()};
        int all_gcd{0};
        int count_ones{0};

        for (const int &num: nums) {
            if (num == 1) {
                count_ones += 1;
            }

            all_gcd = gcd(all_gcd, num);
        }

        if (all_gcd != 1) {
            return -1;
        } 

        if (count_ones > 0) {
            return static_cast<int>(len) - count_ones;
        }

        size_t min_len{numeric_limits<size_t>::max()};

        for (size_t i{0}; i < len && min_len != 2; ++i) {
            int curr_gcd{0};

            for (auto it{nums.cbegin() + i}; it != nums.cend(); ++it) {
                curr_gcd = gcd(curr_gcd, *it);

                if (curr_gcd == 1) {
                    min_len = min(min_len, static_cast<size_t>(it - nums.cbegin()) - i + 1);
                    break;
                }
            }
        }

        int op_need_to_make_one_x_one{static_cast<int>(min_len) - 1};
        int op_need_after_it{static_cast<int>(len) - 1};

        return op_need_to_make_one_x_one + op_need_after_it;
    }
};
