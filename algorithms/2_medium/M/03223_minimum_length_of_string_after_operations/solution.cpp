class Solution {
public:
    int minimumLength(string s) {
        array<int, 26> freqs{};
        int count{0};

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const int& freq : freqs) {
            if (freq > 0) {
                if ((freq & 1) == 1) {
                    count += 1;
                } else {
                    count += 2;
                }
            }
        }

        return count;
    }
};
