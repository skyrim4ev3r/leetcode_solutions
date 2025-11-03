class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<int, 26> freqs_chars{};

        for (const char &ch: chars) {
            freqs_chars[static_cast<size_t>(ch - 'a')] += 1;
        }

        int count{0};

        for (const string &word: words) {
            array<int, 26> freqs{};

            for (const char &ch: word) {
                freqs[static_cast<size_t>(ch - 'a')] += 1;
            }

            bool is_ans{true};
            for (size_t i{0}; i < 26; ++i) {
                if (freqs[i] > freqs_chars[i]) {
                    is_ans = false;
                    break;
                }
            }

            if (is_ans) {
                count += static_cast<int>(word.size());
            }
        }

        return count;
    }
};
