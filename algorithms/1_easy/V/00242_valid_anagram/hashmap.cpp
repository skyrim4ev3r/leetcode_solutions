class Solution {
public:
    static bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        auto freqs = unordered_map<char, int>();     

        for (const char ch : s) {
            freqs[ch] += 1;
        }

        for (const char ch : t) {
            freqs[ch] -= 1;
        }

        for (const auto [_, freq] : freqs) {
            if (freq != 0) {
                return false;
            }
        }

        return true;
    }
};
