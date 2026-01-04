class Solution {
public:
    static string lastNonEmptyString(const string& s) {
        array<int, 26> freqs;
        std::ranges::fill(freqs, 0);

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        const int max {*std::max_element(freqs.begin(), freqs.end())};

        for (int& freq : freqs) {
            freq = std::max(0, freq - max + 1);
        }

        string res;
        res.reserve(26);

        for (auto it {s.crbegin()}; it != s.crend(); ++it) {
            if (freqs[static_cast<size_t>(*it - 'a')] > 0) {
                freqs[static_cast<size_t>(*it - 'a')] -= 1;
                res.push_back(*it);
            }
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};
