class Solution {
    inline static bool is_vowel(const char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    inline static int count_vowels(const string& word) {
        int count {0};

        for (const char& ch : word) {
            if (is_vowel(ch)) {
                count += 1;
            }
        }

        return count;
    }
public:
    static string reverseWords(const string& s) {
        string res;
        res.reserve(s.size());
        istringstream ss {s};
        string part;

        ss >> part;
        const int first_word_vowel_count {count_vowels(part)};
        res += part;

        while (ss >> part) {
            const int curr_vowel_count {count_vowels(part)};

            if (curr_vowel_count == first_word_vowel_count) {
                reverse(part.begin(), part.end());
            }

            res.push_back(' ');
            res += part;
        }

        return res;
    }
};
