typedef ptrdiff_t isize;

class Solution {
    static bool is_sub(const string_view s, const string_view t) {
        const isize s_len = std::ssize(s);
        const isize t_len = std::ssize(t);

        if (s_len < t_len) { return false; }

        if (t_len == 0) { return true; }

        isize t_idx = 0;

        for (isize s_idx = 0; s_idx < s_len; s_idx += 1) {
            if (s[s_idx] == t[t_idx]) {
                t_idx += 1;

                if (t_idx == t_len) {
                    return true;
                }
            }

            if (s_len - s_idx < t_len - t_idx) {
                return false;
            }
        }

        return false;
    }

public:
    static string findLongestWord(const string& s, const vector<string>& dictionary) {
        const isize len = std::ssize(dictionary);
        isize selected_idx = -1;
        isize selected_len = -1;

        for (isize i = 0; i < len; i += 1) {
            if (is_sub(s, dictionary[i])) {
                const isize curr_len = std::ssize(dictionary[i]);

                if (selected_len < curr_len) {
                    selected_idx = i;
                    selected_len = curr_len;
                } else if (selected_len == curr_len && dictionary[selected_idx] > dictionary[i]) {
                    selected_idx = i;
                }
            }
        }

        if (selected_idx == -1) {
            return string();
        }

        return dictionary[selected_idx];
    }
};
