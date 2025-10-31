class Solution {
    inline bool is_vowel(char &c) {
        if (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' ||c=='U') {
            return true;
        }

        return false;
    }
public:
    string reverseVowels(string s) {
        size_t left{0};
        size_t right{s.size() - 1};

        while (left < right) {
            while (left < right && !is_vowel(s[right])) {
                right -= 1;
            }

            while (left < right && !is_vowel(s[left])) {
                left += 1;
            }

            if (left >= right) {
                break;
            }

            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            right -= 1;
            left += 1;
        }

        return s;
    }
};
