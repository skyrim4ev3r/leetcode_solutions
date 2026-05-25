class Solution {
public:
    static int lengthOfLastWord(const string& s) {
        const size_t len = s.size();
        int curr_word_len = 0;
        int last_word_len = 0;

        for (size_t i = 0; i < len; i += 1) {
            if (s[i] == ' ') {
                curr_word_len = 0;
            } else {
                curr_word_len += 1;
                last_word_len = curr_word_len;
            }
        }

        return last_word_len;
    }
};
