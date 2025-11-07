class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {

        const size_t s_len{s.size()};
        size_t s_index{0};

        for (const string &word: words) {

            const size_t word_len{word.size()};
            size_t w_index{0};

            if (word_len > s_len - s_index) {
                return false;
            }

            while (w_index < word_len && word[w_index] == s[s_index]) {
                s_index += 1;
                w_index += 1;
            }

            if (w_index != word_len) {
                return false;
            }

            if (s_index == s_len) {
                return true;
            }
        }

        return false;
    }
};
