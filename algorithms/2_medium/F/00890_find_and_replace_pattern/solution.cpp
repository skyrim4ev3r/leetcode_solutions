class Solution {
    static inline string custom_transform(const string& word) {
        char curr_available{ 'a' };
        array<char, 26> char_map{};
        string res;
        res.reserve(word.size());

        for (const auto& ch : word) {
            const size_t index{ static_cast<size_t>(ch - 'a') };

            if (char_map[index] == 0) {
                char_map[index] = curr_available;
                curr_available += 1;
            }

            res.push_back(char_map[index]);
        }

        return res;
    }
public:
    static vector<string> findAndReplacePattern(const vector<string>& words, const string& pattern) {
        const auto pattern_transformed{ custom_transform(pattern) };
        vector<string> res{};

        for (const auto& word : words) {
            const auto word_transformed{ custom_transform(word) };

            if (word_transformed == pattern_transformed) {
                res.push_back(word);
            }
        }

        return res;
    }
};
