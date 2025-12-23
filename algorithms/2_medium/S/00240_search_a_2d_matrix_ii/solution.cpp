class Solution {
public:
    static inline bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            if (binary_search(row.cbegin(), row.cend(), target)) {
                return true;
            }
        }

        return false;
    }
};
