class Solution {
private:
    const array<array<int, 2>, 4> directions{array<int, 2>{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>> &grid,const size_t rows,const size_t cols,const size_t i,const size_t j) {
        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        for (const auto &[dx, dy]: directions) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            if (new_i >= rows || new_j >= cols) {
                continue;
            }

            dfs(grid, rows, cols, new_i, new_j);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count{0};
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, rows, cols, i, j);
                }
            }
        }

        return count;
    }
};
