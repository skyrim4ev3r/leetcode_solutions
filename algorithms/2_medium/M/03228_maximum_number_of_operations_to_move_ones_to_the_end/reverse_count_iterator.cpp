class Solution {
public:
    int maxOperations(string s) {
        int op_count{0};
        int curr_shift_cost{0};

        for (auto it{s.crbegin()}; it != s.crend(); ++it) {
            if (*it == '1') {
                op_count += curr_shift_cost;
            } else if (it == s.crbegin() || *(it - 1) == '1') {
                curr_shift_cost += 1;
            }
        }

        return op_count;
    }
};
