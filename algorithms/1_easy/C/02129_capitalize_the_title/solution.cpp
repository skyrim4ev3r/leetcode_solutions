class Solution {
public:
    string capitalizeTitle(string title) {
        string res;
        res.reserve(title.size());
        istringstream ss{move(title)};
        string word;

        while (ss >> word) {
            if (!res.empty()) {
                res.push_back(' ');
            }

            if (word.size() < 3) {
                word[0] = tolower(word[0]);
            } else {
                word[0] = toupper(word[0]);
            }

            std::transform(word.begin() + 1, word.end(), word.begin() + 1, [](unsigned char c) { 
                return tolower(c);
            });

            res += word;
        }

        return res;
    }
};
