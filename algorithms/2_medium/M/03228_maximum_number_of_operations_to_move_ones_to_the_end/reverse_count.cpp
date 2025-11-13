class Solution {
public:
    int maxOperations(string s) {
        const size_t len{s.size()};
        int op_count{0};
        int curr_shift_cost{0};

        for (size_t i{len - 1}; i < len; --i) {
            if (s[i] == '1') {
                op_count += curr_shift_cost;
            } else if (i + 1 == len || s[i + 1] == '1') {
                curr_shift_cost += 1;
            }
        }

        return op_count;
    }
};
