int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    const size_t rows = gridSize;
    const size_t cols = gridColSize[0];
    int *dp = (int*) malloc(cols * sizeof(int));
    int *dp_next = (int*) malloc(cols * sizeof(int));
    dp[0] = grid[0][0];
    for  (size_t j = 1; j < cols; j += 1) {
        dp[j] = dp[j - 1] + grid[0][j];
    }

    for  (size_t i = 1; i < rows; i += 1) {
        dp_next[0] = dp[0] + grid[i][0];
        for  (size_t j = 1; j < cols; j += 1) {
            const int from_top = dp[j];
            const int from_left = dp_next[j - 1];
            const int min = from_top > from_left ? from_left : from_top;
            dp_next[j] = min + grid[i][j];
        }
        int *temp = dp;
        dp = dp_next;
        dp_next = temp;
    }

    const int res = dp[cols - 1];
    free(dp);
    free(dp_next);

    return res;
}
