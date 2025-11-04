class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count{0};
        const size_t rows{board.size()};
        const size_t cols{board[0].size()};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (board[i][j] == 'X') {
                    if ((i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) {
                        continue;
                    }

                    count += 1;
                }
            }
        }

        return count;
    }
};
