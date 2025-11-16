class Solution {
public:
    int firstUniqChar(string s) {
        array<pair<int, size_t>, 26> freqs{};
        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {
            const size_t char_as_index{static_cast<size_t>(s[i] - 'a')};

            if (freqs[char_as_index].first == 0) {
                freqs[char_as_index].first = 1;
                freqs[char_as_index].second = i;
            } else {
                freqs[char_as_index].first = 2;
            }
        }

        size_t res{len};

        for (const auto& [count, index] : freqs) {
            if (count == 1) {
                res = min(res, index);
            }
        }

        if (res == len) {
            return -1;
        }

        return static_cast<int>(res);
    }
};
