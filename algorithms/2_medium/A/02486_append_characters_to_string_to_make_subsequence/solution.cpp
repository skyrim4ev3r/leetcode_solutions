class Solution {
public:
    int appendCharacters(string s, string t) {
        size_t s_len{s.size()};
        size_t t_len{t.size()};

        size_t s_index{0};
        size_t t_index{0};

        while (s_index < s_len && t_index < t_len) {
            if (s[s_index] == t[t_index]) {
                t_index += 1;
            }

            s_index += 1;
        }

        return t_len - t_index;
    }
};
