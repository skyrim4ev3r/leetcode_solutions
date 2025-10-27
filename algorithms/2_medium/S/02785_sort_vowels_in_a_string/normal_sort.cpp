class Solution {
    inline bool is_vowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch =='i' || ch =='o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch =='I' || ch =='O' || ch == 'U');
    }
public:
    string sortVowels(string s) {
        vector<char> vec_stack{};

        for (auto &ch: s) {
            if (is_vowel(ch)) {
                vec_stack.push_back(ch);
            }
        }

        sort(vec_stack.rbegin(), vec_stack.rend());

        for (char &ch: s) {
            if (is_vowel(ch)) {
                ch = vec_stack.back();
                vec_stack.pop_back();
            }
        }

        return s;
    }
};
