class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row_vals(static_cast<size_t>(m), 0);
        vector<int> col_vals(static_cast<size_t>(n), 0);
        int count{0};

        for (const auto &index: indices) {
            row_vals[static_cast<size_t>(index[0])] += 1;
            col_vals[static_cast<size_t>(index[1])] += 1;
        }      

        for (const int &row_val: row_vals) {
            for (const int &col_val: col_vals) {
                if (((row_val + col_val) & 1) == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
