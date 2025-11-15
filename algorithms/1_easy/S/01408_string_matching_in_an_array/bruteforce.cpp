class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const size_t len{words.size()};
        vector<string> res{};
        vector<bool> is_inserted(len, false);

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{0}; j < len; ++j) {
                if (i == j || is_inserted[j]) {
                    continue;
                }

                if (words[i].find(words[j]) != std::string::npos) {
                    res.push_back(words[j]);
                    is_inserted[j] = true;
                }
            }
        }

        return res;
    }
};
