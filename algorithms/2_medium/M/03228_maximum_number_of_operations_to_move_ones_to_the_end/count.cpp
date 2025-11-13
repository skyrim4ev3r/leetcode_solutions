class Solution {
public:
    int maxOperations(string s) {
        const size_t len{s.size()};
        int op_count{0};
        int count_ones{0};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] == '1') {
                count_ones += 1;
            } else if (i > 0 && s[i - 1] == '1') {
                op_count += count_ones;
            }
        }

        return op_count;
    }
};
