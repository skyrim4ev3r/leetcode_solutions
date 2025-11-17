class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        int perimeter{0};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0) {
                        perimeter += 1;
                    }

                    if (i == rows - 1 || grid[i + 1][j] == 0) {
                        perimeter += 1;
                    }

                    if (j == 0 || grid[i][j - 1] == 0) {
                        perimeter += 1;
                    }

                    if (j == cols - 1 || grid[i][j + 1] == 0) {
                        perimeter += 1;
                    }
                }
            }
        }

        return perimeter;
    }
};
