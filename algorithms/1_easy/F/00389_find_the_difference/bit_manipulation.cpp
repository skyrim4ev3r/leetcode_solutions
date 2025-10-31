class Solution {
public:
    char findTheDifference(string s, string t) {
        char added_char{0};

        for (const char &ch: s) {
            added_char ^= ch;
        }

        for (const char &ch: t) {
            added_char ^= ch;
        }

        return added_char;
    }
};
