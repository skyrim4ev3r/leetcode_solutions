class Solution {
public:
    int minDeletion(string s, int k) {
        array<int, 26> freqs{};

        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        sort(freqs.rbegin(), freqs.rend());

        return reduce(freqs.begin() + static_cast<size_t>(k), freqs.end(), 0);
    }
};
