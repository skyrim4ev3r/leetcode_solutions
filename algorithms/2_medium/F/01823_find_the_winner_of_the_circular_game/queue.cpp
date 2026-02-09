class Solution {
public:
    static int findTheWinner(const int n, const int k) {
        queue<int> q;
        const size_t k_usize{ static_cast<size_t>(k) };

        for (int i{ 1 }; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() > 1) {
            const size_t curr_len{ q.size() };
            const size_t index_to_del{
                (k_usize % curr_len == 0) ? curr_len - 1 : k % curr_len - 1
            };

            for (size_t i{ 0 }; i < index_to_del; ++i) {
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }

        return q.front();
    }
};
