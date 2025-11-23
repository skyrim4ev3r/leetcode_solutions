class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res{};
        array<char, 128> flags{};

        for (const char& ch : "qwertyuiopQWERTYUIOP") {
            flags[static_cast<size_t>(ch)] = 1;
        }

        for (const char& ch : "asdfghjklASDFGHJKL") {
            flags[static_cast<size_t>(ch)] = 2;
        }

        for (const char& ch : "zxcvbnmZXCVBNM") {
            flags[static_cast<size_t>(ch)] = 4;
        }

        for (const string& word : words) {
            char flag{0};

            for (const char& ch : word) {
                flag |= flags[static_cast<size_t>(ch)];

                if (__builtin_popcount(flag) != 1) {
                    break;
                }
            }

            if (__builtin_popcount(flag) == 1) {
                res.push_back(word);
            }
        }

        return res;
    }
};
