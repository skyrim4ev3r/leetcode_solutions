class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowed_chars(allowed.begin(), allowed.end());
        int count{0};

        for (const string &word: words) {
            bool is_good{true};

            for (const char &ch: word) {
                if (allowed_chars.find(ch) == allowed_chars.end()) {
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
