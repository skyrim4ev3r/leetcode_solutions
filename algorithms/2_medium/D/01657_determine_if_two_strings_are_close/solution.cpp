class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        array<int, 26> freq1{};
        array<int, 26> freq2{};

        for (const char& ch : word1) {
            freq1[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char& ch : word2) {
            freq2[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (size_t i{0}; i < 26; ++i) {
            if ((freq1[i] > 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
