class Solution {
public:
    int possibleStringCount(string word) {
        const size_t len{word.size()};
        int res{0};

        for (size_t i{1}; i < len; ++i) {
            if (word[i] == word[i - 1]) {
                res += 1;
            }
        }

        // The total count of segments is the number of duplicates found (res) plus one
        // for the initial group of characters in the string
        return res + 1;
    }
};
