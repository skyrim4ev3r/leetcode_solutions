class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        array<bool, 26> allowed_chars{};
        int count{0};

        for (const char &ch: allowed) {
            allowed_chars[static_cast<size_t>(ch - 'a')] = true;
        }

        for (const string &word: words) {
            bool is_good{true};

            for (const char &ch: word) {
                if (!allowed_chars[static_cast<size_t>(ch - 'a')]) {
                    is_good = false;
                    break;
                }
            }

            if (is_good) {
                count += 1;
            }
        }

        return count;
    }
};
