class Solution {
public:
    int minimumPushes(string word) {

        array<int, 26> freqs{};

        for (const char &ch: word) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        sort(freqs.rbegin(), freqs.rend());

        int total_cost{0};

        for (size_t i{0}; i < 26; ++i) {
            int curr_cost{1 + static_cast<int>(i) / 8};
            total_cost += freqs[i] * curr_cost;
        }

        return total_cost;
    }
};
