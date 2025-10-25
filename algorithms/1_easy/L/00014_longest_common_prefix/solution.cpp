class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        size_t min_word_len{std::min_element(strs.begin(), strs.end(),[](const string &a, const string &b) {
                return a.size() < b.size();
            }
        )->size()};

        for (size_t word_index{0}; word_index <  min_word_len; ++word_index) {
            const char current_char = strs[0][word_index];

            for (string &word: strs) {
                if (word[word_index] != current_char) {
                    return word.substr(0, word_index);
                }
            }
        }

        return strs[0].substr(0, min_word_len);
    }
};
