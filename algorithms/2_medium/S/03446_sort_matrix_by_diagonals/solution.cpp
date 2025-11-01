class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        const size_t n{grid.size()};

        // Sort upper diagonals
        for (size_t pos{1}; pos < n; ++pos) {
            size_t i{0};
            size_t j{pos};
            vector<int> values{};

            while (j < n) {
                values.push_back(grid[i][j]);
                j += 1;
                i += 1;
            }

            sort(values.begin(), values.end()); 

            i = 0;
            j = pos;
            while (j < n) {
                grid[i][j] = values[i];
                i += 1;
                j += 1;
            }
        }

        // Sort lower diagonals
        for (size_t pos{0}; pos < n; ++pos) {
            size_t i{pos};
            size_t j{0};
            vector<int> values{};

            while (i < n) {
                values.push_back(grid[i][j]);
                j += 1;
                i += 1;
            }

            sort(values.rbegin(), values.rend()); 

            i = pos;
            j = 0;
            while (i < n) {
                grid[i][j] = values[j];
                i += 1;
                j += 1;
            }
        }

        return grid;
    }
};
