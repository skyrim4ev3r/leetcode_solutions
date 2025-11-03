class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        size_t n{mat.size()};
        int sum{0};

        for (size_t i{0}; i < n; ++i) {
            sum += mat[i][i];
            sum += mat[n - 1 -i][i];
        }

        if ((n & 1) == 1) {
            size_t center{n / 2};
            sum -= mat[center][center];
        }

        return sum;
    }
};
