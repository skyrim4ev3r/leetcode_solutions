class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count_negative {0};
        long long sum {0};
        int min_abs_val {numeric_limits<int>::max()};

        for (const auto& row : matrix) {
            for (const int cell : row) {
                if (cell < 0) {
                    count_negative += 1;
                }

                min_abs_val = std::min(min_abs_val, abs(cell));
                sum += static_cast<long long>(abs(cell));
            }
        }

        if ((count_negative & 1) == 1) {
            // Adjust the total sum if there are an odd number of negative values.
            // If there is at least one zero in the matrix, then `min_abs_val` will be zero,
            // and subtracting twice `min_abs_val` will have no effect on the sum,
            // effectively covering that edge case as well.
            sum -= static_cast<long long>(2 * min_abs_val);
        }

        return sum;
    }
};
