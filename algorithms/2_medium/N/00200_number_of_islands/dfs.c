#define WATER '0'
#define LAND '1'
#define LAND_VISITED '2'

void dfs(char** grid,const ptrdiff_t rows,const ptrdiff_t cols,const ptrdiff_t i,const ptrdiff_t j)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != LAND) {
        return;
    }

    grid[i][j] = LAND_VISITED;

    dfs(grid, rows, cols, i + 1, j);
    dfs(grid, rows, cols, i - 1, j);
    dfs(grid, rows, cols, i, j + 1);
    dfs(grid, rows, cols, i, j - 1);
}

int numIslands(char** grid, int grid_size, int* grid_col_size)
{
    int count = 0;
    const ptrdiff_t rows = grid_size;
    const ptrdiff_t cols = grid_col_size[0];

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
