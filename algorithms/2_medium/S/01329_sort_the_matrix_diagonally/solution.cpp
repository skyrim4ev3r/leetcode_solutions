class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const size_t rows{mat.size()};
        const size_t cols{mat[0].size()};
        vector<int> temp;
        temp.reserve(std::max(rows, cols));

        for (size_t start_j{0}; start_j < cols; ++start_j) {
            size_t i{0};
            size_t j{start_j};

            while (i < rows && j < cols) {
                temp.push_back(mat[i][j]);
                i += 1;
                j += 1;
            }

            sort(temp.begin(), temp.end());

            i = 0;
            j = start_j;

            while (i < rows && j < cols) {
                mat[i][j] = temp[i];
                i += 1;
                j += 1;
            }

            temp.clear();
        }

        for (size_t start_i{1}; start_i < rows; ++start_i) {
            size_t i{start_i};
            size_t j{0};

            while (i < rows && j < cols) {
                temp.push_back(mat[i][j]);
                i += 1;
                j += 1;
            }

            sort(temp.begin(), temp.end());

            i = start_i;
            j = 0;

            while (i < rows && j < cols) {
                mat[i][j] = temp[j];
                i += 1;
                j += 1;
            }

            temp.clear();
        }

        return mat;
    }
};
