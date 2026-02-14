class Solution {
public:
    static string reversePrefix(string word, char ch) {
        const size_t index{ word.find(ch) };

        if (index != string::npos) {
            std::reverse(word.begin(), word.begin() + index + 1);
        }

        return word;
    }
};
