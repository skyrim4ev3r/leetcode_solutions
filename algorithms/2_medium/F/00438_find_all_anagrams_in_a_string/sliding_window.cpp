class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res {};

        if (p.size() > s.size()) {
            return res;
        }

        const size_t p_len {p.size()};
        const size_t s_len {s.size()};
        array<int, 26> freqs_window_s {};
        array<int, 26> freqs_p {};

        for (size_t i {0}; i < p_len; ++i) {
            freqs_p[static_cast<size_t>(p[i] - 'a')] += 1;
            freqs_window_s[static_cast<size_t>(s[i] - 'a')] += 1;
        }

        if (freqs_window_s == freqs_p) {
            res.push_back(0);
        }

        const size_t end {s_len - p_len};

        for (size_t i {0}; i < end; ++i) {
            freqs_window_s[static_cast<size_t>(s[i] - 'a')] -= 1;
            freqs_window_s[static_cast<size_t>(s[i + p_len] - 'a')] += 1;

            if (freqs_window_s == freqs_p) {
                res.push_back(static_cast<int>(i + 1));
            }
        }

        return res;
    }
};
