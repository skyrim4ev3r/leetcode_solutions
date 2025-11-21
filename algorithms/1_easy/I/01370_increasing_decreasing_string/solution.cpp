class Solution {
public:
    string sortString(string s) {
        array<int, 26> freqs{};
        string res{};

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        bool flip_flop{true};
        while (res.size() != s.size()) {
            if (flip_flop) {
                for (auto it{freqs.begin()}; it != freqs.end(); ++it) {
                    if (*it > 0) {
                        *it -= 1;
                        res.push_back(static_cast<char>(it - freqs.begin()) + 'a');
                    }
                }
            } else {
                for (auto it{freqs.rbegin()}; it != freqs.rend(); ++it) {
                    if (*it > 0) {
                        *it -= 1;
                        res.push_back('z' - static_cast<char>(it - freqs.rbegin()));
                    }
                }
            }

            flip_flop = !flip_flop;
        }

        return res;
    }
};
