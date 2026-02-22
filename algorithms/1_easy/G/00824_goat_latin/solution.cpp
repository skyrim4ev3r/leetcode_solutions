class Solution {
    static inline bool is_vowel(const char& ch) {
        return (
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
        );
    }
public:
    static string toGoatLatin(const string& sentence) {
        istringstream iss{ sentence };
        ostringstream oss{};
        string word;
        string end{ "maa" };

        while (iss >> word) {
            if (!is_vowel(word[0])) {
                std::rotate(word.begin(), word.begin() + 1, word.end());
            }

            word += end;
            end += "a";

            if (oss.tellp() != 0) {
                oss << ' ';
            }

            oss << word;
        }

        return oss.str();
    }
};
