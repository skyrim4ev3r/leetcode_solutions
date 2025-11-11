class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const size_t n{grid.size()};
        int area{0};

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                if (grid[i][j] > 0) {
                    area += 2;
                    const int up{i > 0 ? grid[i - 1][j] : 0};
                    const int left{j > 0 ? grid[i][j - 1] : 0};
                    const int down{i < n - 1 ? grid[i + 1][j] : 0};
                    const int right{j < n - 1 ? grid[i][j + 1] : 0};

                    area += max(0, grid[i][j] - up);
                    area += max(0, grid[i][j] - down);
                    area += max(0, grid[i][j] - left);
                    area += max(0, grid[i][j] - right);
                }
            }
        }

        return area;
    }
};
