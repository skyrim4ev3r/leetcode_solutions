const array<array<int, 2>, 8> DIRECTIONS {
    array<int, 2>{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};

const size_t board_size {8};

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        array<array<bool, board_size>, board_size> board {};
        vector<vector<int>> res {};

        for (const auto& q : queens) {
            board[static_cast<size_t>(q[0])][static_cast<size_t>(q[1])] = true;
        }

        const size_t i_st {static_cast<size_t>(king[0])};
        const size_t j_st {static_cast<size_t>(king[1])};

        for (const auto& [dx, dy] : DIRECTIONS) {
            size_t i {static_cast<size_t>(static_cast<int>(i_st) + dx)};
            size_t j {static_cast<size_t>(static_cast<int>(j_st) + dy)};

            while (i < board_size && j < board_size) {
                if (board[i][j]) {
                    res.push_back(vector<int>{static_cast<int>(i), static_cast<int>(j)});
                    break;
                }

                i = static_cast<size_t>(static_cast<int>(i) + dx);
                j = static_cast<size_t>(static_cast<int>(j) + dy);
            }
        }

        return res;
    }
};
