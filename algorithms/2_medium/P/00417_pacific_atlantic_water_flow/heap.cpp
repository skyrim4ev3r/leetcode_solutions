/*
    using two min_heap, one for atlantic ocean, one for pacific ocean
    using two is_visited, one for atlantic ocean, one for pacific ocean

    using a grid with defalut valu of 0 and size of m*n

    incremnet every cells in grid that are reachable from """atlantic ocean""" by """1"""
    incremnet every cells in grid that are reachable from """pacific ocean""" by """1"""

    at final every cells in grid with value of """2""" are reachable from both side, and we can add all of them to """result"""
*/
class Solution {
    const array<array<int, 2>, 4> directions{array<int, 2>{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    struct Cell {
        int height;
        size_t i;
        size_t j;
        bool operator<(const Cell& other) const {
            return height > other.height; // Reverse for min-heap
        }
    };

    inline void solve(
        const vector<vector<int>>& heights,
        vector<vector<int>> &grid,
        priority_queue<Cell> &pq,
        vector<vector<bool>> &is_visited
    ) {
        const size_t rows{heights.size()};
        const size_t cols{heights[0].size()};

         while (!pq.empty()) {

            const auto [old_height, old_i, old_j] = pq.top();
            pq.pop();

            for (const auto &[dx, dy]: directions) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(old_i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(old_j) + dy)};

                if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                int new_height = heights[new_i][new_j];

                if (new_height < old_height) {
                    continue;
                }

                grid[new_i][new_j] += 1;
                pq.push(Cell {new_height, new_i, new_j});
            }

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const size_t rows{heights.size()};
        const size_t cols{heights[0].size()};

        priority_queue<Cell> atlantic_pq{};
        priority_queue<Cell> pacific_pq{};

        vector<vector<int>> grid = vector(rows, vector<int>(cols, 0));
        vector<vector<bool>> atlantic_is_visited = vector(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific_is_visited = vector(rows, vector<bool>(cols, false));


        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (i == 0 || j == 0) {
                    pacific_pq.push(Cell {heights[i][j], i, j});
                    pacific_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }

                if (i == rows - 1 || j == cols - 1) {
                    atlantic_pq.push(Cell {heights[i][j], i, j});
                    atlantic_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }
            }
        }

        solve(heights, grid, atlantic_pq, atlantic_is_visited);
        solve(heights, grid, pacific_pq, pacific_is_visited);

        vector<vector<int>> res{};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    res.push_back(vector<int>{static_cast<int>(i), static_cast<int>(j)});
                }
            }
        }

        return res;
    }
};
