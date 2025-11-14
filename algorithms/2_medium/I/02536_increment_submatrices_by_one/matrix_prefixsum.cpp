class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        const size_t n_usize{static_cast<size_t>(n)};
        vector<vector<int>> res(n_usize, vector<int>(n_usize, 0));

        for (const auto& query : queries) {
            const size_t i1{static_cast<size_t>(query[0])};
            const size_t j1{static_cast<size_t>(query[1])};
            const size_t i2{static_cast<size_t>(query[2])};
            const size_t j2{static_cast<size_t>(query[3])};

            for (size_t i{i1}; i <= i2; ++i) {
                res[i][j1] += 1;

                if (j2 + 1 < n_usize) {
                    res[i][j2 + 1] -= 1;
                }
            }
        }

        for (size_t i{0}; i < n_usize; ++i) {
            for (size_t j{1}; j < n_usize; ++j) {
                res[i][j] += res[i][j - 1];
            }
        }

        return res;
    }
};
