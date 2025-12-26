class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count {0};
        const size_t len {words.size()};

        for (size_t i {0}; i < len; ++i) {
            for (size_t j {i + 1}; j < len; ++j) {
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
