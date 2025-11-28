class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        if (k == 0) {
            return 0;
        }

        for (auto& row : grid) {
            sort(row.begin(), row.end(), [](const int& a, const int& b){
                return b < a;
            });
        }

        priority_queue<int> heap{};
        const size_t k_usize{static_cast<size_t>(k)};
        const size_t n{grid.size()};

        for (size_t i{0}; i < n; ++i) {
            const size_t limit{static_cast<size_t>(limits[i])};

            for (size_t j{0}; j < limit; ++j) {
                if (grid[i][j] == 0 || (heap.size() == k_usize && grid[i][j] <= -1 * heap.top())) {
                    break;
                }

                heap.push(-grid[i][j]);

                if (heap.size() > k_usize) {
                    heap.pop();
                }
            }
        }

        long long sum{0};

        while (!heap.empty()) {
            sum += (-1 * static_cast<long long >(heap.top()));
            heap.pop();
        }

        return sum;
    }
};
