class Solution {
    static inline bool is_vowel(const char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    static bool isValid(const string& word) {
        if (word.size() < 3) {
            return false;
        }

        bool has_vowel {false};
        bool has_cons {false};

        for (const char& ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                if (is_vowel(ch + 32)) {
                    has_vowel = true;
                } else {
                    has_cons = true;
                }
            } else if (ch >= 'a' && ch <= 'z') {
                if (is_vowel(ch)) {
                    has_vowel = true;
                } else {
                    has_cons = true;
                }
            } else if (ch >= '0' && ch <= '9') {
                continue;
            } else {
                return false;
            }
        }

        return  has_vowel && has_cons;
    }
};
