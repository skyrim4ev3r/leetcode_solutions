class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max{-1};

        for (const string &sentence: sentences) {
            int count{1};
            const size_t len{sentence.size()};

            for (size_t i{0}; i < len; ++i) {
                if (sentence[i] == ' ') {
                    count += 1;
                }
            }

            max = std::max(max, count);
        }

        return max;
    }
};
