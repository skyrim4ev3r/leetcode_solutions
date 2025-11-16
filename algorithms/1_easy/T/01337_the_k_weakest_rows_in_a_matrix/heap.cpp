class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<size_t, size_t>> heap;
        const size_t k_usize{static_cast<size_t>(k)};

        for (size_t index{0}; const auto& row : mat) {
            size_t count = std::count(row.cbegin(), row.cend(), 1);

            if (heap.size() < k_usize) {
                heap.push({count, index});
            } else {
                if (heap.top().first > count) {
                    heap.push({count, index});
                    heap.pop();
                }
            }

            index += 1;
        }

        const size_t len{heap.size()};
        vector<int> res(len, 0);

        for (size_t i{len - 1}; i < len; --i) {
            res[i] = static_cast<int>(heap.top().second);
            heap.pop();
        }

        return res;
    }
};
