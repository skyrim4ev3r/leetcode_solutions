class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken_set(brokenLetters.begin(), brokenLetters.end());
        istringstream ss(text);
        string word;
        int count{0};

        while (ss >> word) {
            bool had_broken_char{false};

            for (const char &ch: word) {
                if (broken_set.contains(ch)) {
                    had_broken_char = true;
                    break;
                }
            }

            if (!had_broken_char) {
                ++count;
            }
        }

        return count;
    }
};
