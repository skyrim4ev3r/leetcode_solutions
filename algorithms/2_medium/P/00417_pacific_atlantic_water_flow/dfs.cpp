/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in both is_visited are reachable from both side, and we can add all of them to """result"""
*/
/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in both is_visited are reachable from both side, and we can add all of them to """result"""
*/
class Solution {
private:
    const array<array<int, 2>, 4> directions{array<int, 2>{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    void dfs(
        const vector<vector<int>>& heights,
        vector<vector<bool>> &is_visited,
        const size_t rows,
        const size_t cols,
        const size_t i,
        const size_t j
    ) const {
        is_visited[i][j] = true;

        for (const auto &[dx, dy]: directions) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j] || heights[new_i][new_j] < heights[i][j]) {
                continue;
            }

            dfs(heights, is_visited, rows, cols, new_i, new_j);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const size_t rows{heights.size()};
        const size_t cols{heights[0].size()};

        vector<vector<bool>> atlantic_is_visited(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific_is_visited(rows, vector<bool>(cols, false));

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (i == 0 || j == 0) {
                    dfs(heights, pacific_is_visited, rows, cols, i, j);
                }

                if (i == rows - 1 || j == cols - 1) {
                    dfs(heights, atlantic_is_visited, rows, cols, i, j);
                }
            }
        }

        vector<vector<int>> res{};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (atlantic_is_visited[i][j] && pacific_is_visited[i][j]) {
                    res.push_back(vector<int>{static_cast<int>(i), static_cast<int>(j)});
                }
            }
        }

        return res;
    }
};
