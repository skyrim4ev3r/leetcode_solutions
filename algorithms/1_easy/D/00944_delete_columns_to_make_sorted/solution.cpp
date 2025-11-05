class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const size_t rows{strs.size()};
        const size_t cols{strs[0].size()};
        int count{0};

        for (size_t j{0}; j < cols; ++j) {
            bool is_sorted{true};

            for (size_t i{1}; i < rows; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    is_sorted = false;
                    break;
                }
            }

            if (!is_sorted) {
                count += 1;
            }
        }

        return count;
    }
};
