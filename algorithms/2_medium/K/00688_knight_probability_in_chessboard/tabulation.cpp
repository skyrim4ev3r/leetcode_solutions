typedef ptrdiff_t isize;

constexpr isize dirs_rows = 8;
constexpr isize directions[dirs_rows][2] = {
    {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    {1, 2}, {2, 1}, {2, -1}, {1, -2},
};

class Solution {
public:
    double knightProbability(int n_i32, int k, int row_i32, int col_i32) {
        const isize n = n_i32, row = row_i32, col = col_i32;
        assert(row >= 0 && col >= 0 && row < n && col < n && k >= 0);
        if (k == 0) { return 1.0; };
        auto dp = vector<double>(static_cast<size_t>(n * n * 2));
        double* curr = &dp[0];
        double* next = &dp[n * n];
        for (isize r = 0; r < n; r += 1) {
            for (isize c = 0; c < n; c += 1) {
                curr[r * n + c] = 0.0;
                next[r * n + c] = 1.0;
            }
        }

        for (int i = 1; i <= k; i += 1) {
            for (isize r = 0; r < n; r += 1) {
                for (isize c = 0; c < n; c += 1) {
                    const isize curr_memo_idx = r * n + c;
                    double prob = 0.0;
                    for (auto [dx, dy] : directions) {
                        const isize nr = r + dx;
                        const isize nc = c + dy;
                        if (nr >= 0 && nc >= 0 && nr < n && nc <n) {
                            const isize next_memo_idx = nr * n + nc;
                            prob += next[next_memo_idx];
                        }
                    }
                    curr[curr_memo_idx] = prob / dirs_rows;
                }
            }

            double* temp = next;
            next = curr;
            curr = temp; 
        }

        return next[row * n + col];
    }
};
