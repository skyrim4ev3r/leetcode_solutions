class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const size_t rows{triangle.size()};

        for (size_t curr_row{rows - 2}; curr_row < rows; --curr_row) {
            const size_t next_row{curr_row + 1};
            const size_t curr_row_len{triangle[curr_row].size()};

            for (size_t curr_col{0}; curr_col < curr_row_len; ++curr_col) {
                triangle[curr_row][curr_col] += min(triangle[next_row][curr_col], triangle[next_row][curr_col + 1]);
            }
        }

        return triangle[0][0];
    }
};
