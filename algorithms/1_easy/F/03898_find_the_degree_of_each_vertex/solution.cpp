class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        const size_t n = matrix.size();
        auto res = vector<int>(n);

        for (size_t i = 0; i < n; i += 1) {
            res[i] = reduce(matrix[i].cbegin(), matrix[i].cend(), 0);
        }

        return res;
    }
};
