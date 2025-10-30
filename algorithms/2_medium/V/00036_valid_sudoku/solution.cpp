class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check all rows are valid
        for (size_t i{0}; i < 9; ++i) {
            array<bool, 9> is_seen{};

            for (size_t j{0}; j < 9; ++j) {
                if (board[i][j] != '.') {
                    size_t is_seen_index = board[i][j] - '1';
                    if (is_seen[is_seen_index]) {
                        return false;
                    }
                    is_seen[is_seen_index] = true;
                }
            }
        }

        // Check all cols are valid
        for (size_t j{0}; j < 9; ++j) {
            array<bool, 9> is_seen{};

            for (size_t i{0}; i < 9; ++i) {
                if (board[i][j] != '.') {
                    int is_seen_index = board[i][j] - '1';

                    if (is_seen[is_seen_index]) {
                        return false;
                    }

                    is_seen[is_seen_index] = true;
                }
            }
        }

       // Check all 3*3 sub-boxes
        for (size_t cell{0}; cell < 9; ++cell) {
            array<bool, 9> is_seen{};

            size_t start_i{(cell / 3) * 3};
            size_t start_j{(cell % 3) * 3};

            for (size_t i{start_i}; i < start_i + 3; ++i) {
                for (size_t j{start_j}; j < start_j + 3; ++j) {
                    if (board[i][j] != '.') {
                        int is_seen_index = board[i][j] - '1';

                        if (is_seen[is_seen_index]) {
                            return false;
                        }

                        is_seen[is_seen_index] = true;
                    }
                }
            }
        }

        return true;
    }
};
