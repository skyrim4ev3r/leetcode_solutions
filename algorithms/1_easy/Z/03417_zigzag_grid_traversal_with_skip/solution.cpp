class Solution {
public:
    const vector<int> zigzagTraversal(const vector<vector<int>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        const size_t total{ rows * cols };
        vector<int> res;
        res.reserve((total >> 1) + (total & 1));

        for (size_t step{ 0 }; step < total; step += 2) {
            const size_t i{ step / cols };
            const size_t j{ (i & 1) == 0 ? step % cols : cols - 1 -  (step % cols) };
            res.push_back(grid[i][j]);
        }

        return res;
    }
};
