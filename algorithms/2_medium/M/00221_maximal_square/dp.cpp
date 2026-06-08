class Solution {
public:
    static int maximalSquare(const vector<vector<char>>& matrix) {
        assert(matrix.size() > 0 && matrix[0].size() > 0);
        const ptrdiff_t rows = std::ssize(matrix);
        const ptrdiff_t cols = std::ssize(matrix[0]);
        auto dp = vector<int>(2 * (cols + 1), 0);
        int* curr = &dp[0];
        int* next = &dp[cols + 1];
        int max_side = 0;

        for (ptrdiff_t i = rows - 1; i >= 0; i -= 1) {
            for (ptrdiff_t j = cols - 1; j >= 0; j -= 1) {
                if (matrix[i][j] == '1') {
                    curr[j] = 1 + std::min(next[j + 1], std::min(next[j], curr[j + 1]));
                    max_side = std::max(max_side, curr[j]);
                }
            }

            int* temp = curr;
            curr = next;
            next = temp;

            std::memset(curr, 0, (cols + 1) * sizeof(*curr));
        }

        return max_side * max_side;
    }
};
