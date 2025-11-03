class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t len1{word1.size()}, len2{word2.size()};

        string res{};
        res.reserve(len1 + len2);

        size_t min_len = std::min(len1, len2);

        for (size_t index{0}; index < min_len; ++index) {
            res.push_back(word1[index]);
            res.push_back(word2[index]);
        }

        res.append(word1, min_len, len1 - min_len);
        res.append(word2, min_len, len2 - min_len);

        return res;
    }
};
