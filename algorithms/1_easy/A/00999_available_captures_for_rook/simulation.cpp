class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const size_t n{8};
        array<array<int, 2>, 4> directions{array<int, 2>{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                if (board[i][j] == 'R') {
                    int count{0};

                    for (const auto& [dx, dy] : directions) {
                        size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                        size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                        while (new_i < n && new_j < n && board[new_i][new_j] == '.') {
                            new_i += dx;
                            new_j += dy;
                        }

                        if (new_i < n && new_j < n && board[new_i][new_j] == 'p') {
                            count += 1;
                        }
                    }

                    return count;
                }
            }
        }

        return -1;
    }
};
