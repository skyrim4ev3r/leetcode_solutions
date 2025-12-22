class Solution {
    inline bool check_win(vector<string>& b, size_t n, char player) {
        for (size_t i{0}; i < n; ++i) {
            bool is_winning{true};

            for (size_t j{0}; j < n; ++j) {
                if (b[i][j] != player) {
                    is_winning = false;
                    break;
                }
            }

            if (is_winning) {
                return true;
            }
        }

        for (size_t j{0}; j < n; ++j) {
            bool is_winning{true};

            for (size_t i{0}; i < n; ++i) {
                if (b[i][j] != player) {
                    is_winning = false;
                    break;
                }
            }

            if (is_winning) {
                return true;
            }
        }

        bool is_winning{true};;
        for (size_t i{0}; i < n; ++i) {
            if (b[i][i] != player) {
                is_winning = false;
                break;
            }
        }

        if (is_winning) {
            return true;
        }

        for (size_t i{0}; i < n; ++i) {
            if (b[i][n - 1 - i] != player) {
                return false;
            }
        }

        return true;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        const size_t n{board.size()};
        int balance{0};

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                if (board[i][j] == 'X') {
                    balance += 1;
                } else if (board[i][j] == 'O') {
                    balance -= 1;
                }
            }
        }

        if (balance > 1 || balance < 0) {
            return false;
        };

        bool is_player1_winner{check_win(board, n, 'X')};
        bool is_player2_winner{check_win(board, n,'O')};

        if (
            (is_player1_winner && is_player2_winner) ||
            (is_player1_winner && balance == 0) ||
            (is_player2_winner && balance == 1)
        ) {
            return false;
        }

        return true;
    }
};
