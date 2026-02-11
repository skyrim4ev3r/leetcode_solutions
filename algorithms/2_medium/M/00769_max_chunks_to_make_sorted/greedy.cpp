class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const size_t len{ arr.size() };
        size_t curr_best{ 0 };
        int count{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            curr_best = std::max(curr_best, static_cast<size_t>(arr[i]));

            if (i == curr_best) {
                count += 1;
            }
        }

        return count;
    }
};
