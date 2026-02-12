class Solution {
public:
    static vector<vector<int>> reconstructMatrix(const int upper, const int lower, const vector<int>& colsum) {
        const int sum{ std::reduce(colsum.cbegin(), colsum.cend(), 0) };

        if (sum != upper + lower) {
            return vector<vector<int>>{};
        }

        const int count_twos{ static_cast<int>(std::count(colsum.cbegin(), colsum.cend(), 2)) };

        if (count_twos > upper || count_twos > lower) {
            return vector<vector<int>>{};
        }

        int remain_upper{ upper - count_twos };
        int remian_lower{ lower - count_twos };

        const size_t cols{ colsum.size() };
        const size_t rows{ 2 };
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (size_t j{ 0 }; j < cols; ++j) {
            if (colsum[j] == 1) {
                if (remain_upper > 0) {
                    res[0][j] = 1;
                    remain_upper -= 1;
                } else {
                    res[1][j] = 1;
                    remian_lower -= 1;
                }
            } else if (colsum[j] == 2) {
                res[0][j] = 1;
                res[1][j] = 1;
            }
        }

        return res;
    }
};
