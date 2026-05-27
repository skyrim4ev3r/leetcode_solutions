static const ssize_t DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
    static void dfs(
        const vector<vector<char>>& board,
        const size_t rows,
        const size_t cols,
        const size_t i,
        const size_t j,
        vector<vector<bool>>& is_visited,
        const string &word,
        const size_t word_len,
        const size_t word_idx,
        bool &is_find
    ) {
        if (is_find) { return; }

        if (word_idx == word_len) {
            is_find = true;
            return;
        }

        if (i >= rows || j >= cols || is_visited[i][j] || board[i][j] != word[word_idx]) {
            return;
        }

        is_visited[i][j] = true;

        for (const auto [dx, dy] : DIRECTIONS) {
            const size_t new_i = static_cast<ssize_t>(i) + dx;
            const size_t new_j = static_cast<ssize_t>(j) + dy;
            dfs(board, rows, cols, new_i, new_j, is_visited, word, word_len, word_idx + 1, is_find);
        }

        is_visited[i][j] = false;
    }
public:
    static bool exist(const vector<vector<char>>& board, const string& word) {
        const size_t rows = board.size();
        const size_t cols = board[0].size();
        const size_t word_len = word.size();
        const size_t word_idx = 0;
        auto is_visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        bool is_find = false;

        for (size_t i = 0; i < rows; i += 1) {
            for (size_t j = 0; j < cols; j += 1) {
                dfs(board, rows, cols, i, j, is_visited, word, word_len, word_idx, is_find);

                if(is_find) {
                    return true;
                }
            }
        }

        return false;
    }
};