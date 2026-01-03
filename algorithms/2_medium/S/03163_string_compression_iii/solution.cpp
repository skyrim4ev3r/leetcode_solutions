class Solution {
public:
    string compressedString(string word) {
        const size_t len {word.size()};
        string res {};
        char count {'0'};

        for (size_t i {0}; i < len; ++i) {
            if (i > 0 && word[i] == word[i - 1]) {
                count += 1;
            } else {
                if (count > '0') {
                    res.push_back(count);
                    res.push_back(word[i - 1]);
                }

                count = '1';
            }

            if (count == '9' || i == len - 1) {
                res.push_back(count);
                res.push_back(word[i]);
                count = '0';
            }
        }

        return res;
    }
};
