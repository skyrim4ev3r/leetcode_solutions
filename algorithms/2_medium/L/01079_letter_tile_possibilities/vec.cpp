class Solution {
    static int backtrack(vector<int>& freqs, const size_t len) {
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            if (freqs[i] != 0) {
                freqs[i] -= 1;
                count += 1 + backtrack(freqs, len);
                freqs[i] += 1;
            }
        }

        return count;
    }

public:
    static int numTilePossibilities(const string& tiles) {
        array<int, 26> freqs{};

        for (const char& ch : tiles) {
            freqs[static_cast<size_t>(ch - 'A')] += 1;
        }

        vector<int> valid_freqs;
        valid_freqs.reserve(26);

        for (const int& freq : freqs) {
            if (freq > 0) {
                valid_freqs.push_back(freq);
            }
        }

        return backtrack(valid_freqs, valid_freqs.size());
    }
};
