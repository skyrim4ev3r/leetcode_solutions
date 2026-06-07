constexpr ptrdiff_t table_size = 256;
constexpr ptrdiff_t unseen = -1;

class Solution {
public:
    static bool isIsomorphic(const string& s, const string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        const ptrdiff_t len = static_cast<ptrdiff_t>(s.size());
        ptrdiff_t s_first_seen[table_size];
        ptrdiff_t t_first_seen[table_size];

        for (ptrdiff_t i = 0; i < table_size; i++) {
            s_first_seen[i] = unseen;
            t_first_seen[i] = unseen;
        }

        for (ptrdiff_t i = 0; i < len; i += 1) {
            const ptrdiff_t ch_s_idx = static_cast<unsigned char>(s[i]);
            const ptrdiff_t ch_t_idx = static_cast<unsigned char>(t[i]);

            if (s_first_seen[ch_s_idx] == unseen) {
                s_first_seen[ch_s_idx] = i;
            }

            if (t_first_seen[ch_t_idx] == unseen) {
                t_first_seen[ch_t_idx] = i;
            }

            if (s_first_seen[ch_s_idx] != t_first_seen[ch_t_idx]) {
                return false;
            }
        }

        return true;
    }
};
