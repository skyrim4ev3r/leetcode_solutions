class Solution {
public:
    int maxOperations(string s) {
        int op_count{0};
        int count_ones{0};

        for (auto it{s.cbegin()}; it != s.cend(); ++it) {
            if (*it == '1') {
                count_ones += 1;
            } else if (it != s.cbegin() and *(it - 1) == '1') {
                op_count += count_ones;
            }
        }

        return op_count;
    }
};
