class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd_count {0};
        int even_count {0};
        int switch_count {0};
        bool prev_is_even {!(nums[0] % 2 == 0)};

        for (const int& num : nums) {
            bool curr_is_even {num % 2 == 0};

            if (curr_is_even) {
                even_count += 1;
            } else {
                odd_count += 1;
            }

            if (curr_is_even !=  prev_is_even) {
                prev_is_even = curr_is_even;
                switch_count += 1;
            }
        }

        return max(switch_count, max(even_count, odd_count));
    }
};
