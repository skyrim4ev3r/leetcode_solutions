static constexpr char WATER = '0';
static constexpr char LAND = '1';
static constexpr char LAND_VISITED = '2';

class Solution {
    static void dfs(vector<vector<char>>& grid,const ptrdiff_t rows,const ptrdiff_t cols,const ptrdiff_t i,const ptrdiff_t j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != LAND) {
            return;
        }

        grid[i][j] = LAND_VISITED;

        dfs(grid, rows, cols, i + 1, j);
        dfs(grid, rows, cols, i - 1, j);
        dfs(grid, rows, cols, i, j + 1);
        dfs(grid, rows, cols, i, j - 1);
    }
public:
    static int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        const ptrdiff_t rows = static_cast<ptrdiff_t>(grid.size());
        const ptrdiff_t cols = static_cast<ptrdiff_t>(grid[0].size());

        for (ptrdiff_t i = 0; i < rows; i += 1) {
            for (ptrdiff_t j = 0; j < cols; j += 1) {
                if (grid[i][j] == LAND) {
                    count += 1;
                    dfs(grid, rows, cols, i, j);
                }
            }
        }

        return count;
    }
};
