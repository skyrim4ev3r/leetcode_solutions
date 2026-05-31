class Solution {
public:
    static vector<int> getRow(int numIndex) {
        const size_t final_len = 1 + static_cast<size_t>(numIndex);

        vector<int> curr;
        curr.reserve(final_len);
        curr.push_back(1);

        vector<int> next;
        next.reserve(final_len);

        while (curr.size() != final_len) {
            const size_t curr_len = curr.size();

            next.clear();
            next.push_back(1); // First element always 1
            for (size_t i = 1; i < curr_len; ++i) {
                next.push_back(curr[i] + curr[i - 1]);
            }
            next.push_back(1); // Last element always 1
 
            std::swap(curr, next);
        }

        return curr;
    }
};
