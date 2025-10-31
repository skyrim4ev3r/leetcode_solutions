class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        const size_t rows{static_cast<size_t>(numRows)};
        vector<vector<int>> res;

        res.push_back(vector<int>{1});

        for (size_t i{1}; i < rows; ++i) {
            vector<int> tmp;

            for (size_t j{0};j <= i; ++j) {
                int curr_val{0};

                if (j < i) {
                    curr_val += res[i - 1][j];
                }

                if (j > 0) {
                    curr_val += res[i - 1][j - 1];
                }

                tmp.push_back(curr_val);
            }

            res.push_back(tmp);
        }

        return res;
    }
};
