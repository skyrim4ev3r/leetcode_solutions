class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        const size_t rows{static_cast<size_t>(m)};
        const size_t cols{static_cast<size_t>(n)};
        vector<vector<int>> res;

        if (rows * cols != original.size()) {
            return res;
        }

        res.reserve(rows);

        for (size_t i{0}; i < rows; ++i) {
            res.emplace_back(vector<int>(original.begin() + i * cols, original.begin() + (i + 1) * cols));
        }

        return res;
    }
};
