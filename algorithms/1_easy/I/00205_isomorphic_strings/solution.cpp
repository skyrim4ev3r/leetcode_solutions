class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<int, 128> first_seen_s;
        for (int& f : first_seen_s) {
            f = -1;
        }

        array<int, 128> first_seen_t;
        for (int& f : first_seen_t) {
            f = -1;
        }

        const size_t len{s.size()};
        for (size_t i{0}; i < len; ++i) {
            const size_t ch_s_as_index{static_cast<size_t>(s[i])};
            const size_t ch_t_as_index{static_cast<size_t>(t[i])};

            if (first_seen_s[ch_s_as_index] == -1) {
                first_seen_s[ch_s_as_index] = static_cast<int>(i);
            }

            if (first_seen_t[ch_t_as_index] == -1) {
                first_seen_t[ch_t_as_index] = static_cast<int>(i);
            }

            if (first_seen_s[ch_s_as_index] != first_seen_t[ch_t_as_index]) {
                return false;
            }
        }

        return true;
    }
};
