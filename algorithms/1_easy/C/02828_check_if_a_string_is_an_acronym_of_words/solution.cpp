class Solution {
public:
    static bool isAcronym(const vector<string>& words, const string& s) {
        if (s.size() != words.size()) {
            return false;
        }

        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] != words[i][0]) {
                return false;
            }
        }

        return true;
    }
};
