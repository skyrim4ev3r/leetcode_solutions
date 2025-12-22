class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const size_t rows{strs.size()};
        const size_t cols{strs[0].size()};
        vector<bool> is_sorted(rows, false);
        int count{0};

        for (size_t j{0}; j < cols; ++j) {
            bool should_delete{false};

            for (size_t i{1}; i < rows; ++i) {
                if (!is_sorted[i]) {
                    if (strs[i][j] < strs[i - 1][j]) {
                        should_delete =true;
                        break;
                    }
                }
            }

            if (should_delete) {
                count += 1;
            } else {
                bool are_all_sorted{true};

                for (size_t i{1}; i < rows; ++i) {
                    is_sorted[i] = is_sorted[i] | (strs[i][j] > strs[i - 1][j]);
                    are_all_sorted &= is_sorted[i];
                }

                if (are_all_sorted) {
                    break;
                }
            }
        }

        return count;
    }
};
